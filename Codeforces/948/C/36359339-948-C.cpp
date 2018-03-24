#include<bits/stdc++.h>

using namespace std;

#define SEGDATA long long
#define MAX_N 100005

SEGDATA segTree[262144], lz[262144], k[(int)1e5+5], o[(int)1e5+5];
bool old[262144];
int a[(int)1e5+5], t[(int)1e5+5];

int n;

void updateSegTree(int r,int lo,int hi,int a,int b,SEGDATA val) {
	if(old[r]) {
		segTree[r] += (hi-lo+1) * lz[r];
		if(lo != hi) {
			old[r<<1] = old[(r<<1)|1] = 1;
			lz[r<<1] += lz[r];
			lz[(r<<1)|1] += lz[r];
		}
		old[r] = lz[r] = 0;
	}
	if(lo > b || hi < a) {
		return;
	} else if(a <= lo && b >= hi) {
		segTree[r] += (hi-lo+1) * val;
		if(lo != hi) {
			old[r<<1] = old[(r<<1)|1] = 1;
			lz[r<<1] += val;
			lz[(r<<1)|1] += val;
		}
	} else {
		int mid = (lo+hi)>>1;
		updateSegTree(r<<1,lo,mid,a,b,val);
		updateSegTree((r<<1)|1,mid+1,hi,a,b,val);
		segTree[r] = segTree[r<<1]+segTree[(r<<1)|1];
	}
}

SEGDATA querySegTree(int r,int lo,int hi,int a,int b) {
	if(old[r]) {
		segTree[r] += (hi-lo+1) * lz[r];
		if(lo != hi) {
			old[r<<1] = old[(r<<1)|1] = 1;
			lz[r<<1] += lz[r];
			lz[(r<<1)|1] += lz[r];
		}
		old[r] = lz[r] = 0;
	}
	if(lo > b || hi < a) {
		return 0;
	} else if(a <= lo && b >= hi) {
		return segTree[r];
	} else {
		int mid = (lo+hi)>>1;
		return querySegTree(r<<1,lo,mid,a,b)+querySegTree((r<<1)|1,mid+1,hi,a,b);
	}
}

int bs(int l, int r, int x) {
	int lo = l, hi = r, ans = l-1;
	while(lo <= hi) {
		int mid = lo+hi>>1;
		if(k[mid]-k[l-1] < x) {
			ans = mid;
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= n; i++) k[i] = t[i];
	for(int i = 1; i <= n; i++) k[i] += k[i-1];
	for(int i = 1; i <= n; i++) {
		int l = i, r = bs(i, n, a[i]);
		updateSegTree(1, 1, n, l, r, 1);
		o[r+1] += (r >= l) ? a[i]-k[r]+k[l-1] : a[i];
		cout << querySegTree(1, 1, n, i, i) * t[i] + o[i] << " \n"[i == n];
	}
	return 0;
}
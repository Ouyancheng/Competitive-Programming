#include<bits/stdc++.h>

using namespace std;

#define SEGDATA int
#define MAX_N 2000005

SEGDATA segTree[4194304];

// User-defined variables
int n,h,a,b;

void updateSegTree(int r,int lo,int hi,int a,int b,SEGDATA val) {
	if(lo > b || hi < a) {
		return;
	} else if(a <= lo && b >= hi) {
		segTree[r] += val;
	} else {
		int mid = (lo+hi)>>1;
		updateSegTree(r<<1,lo,mid,a,b,val);
		updateSegTree((r<<1)|1,mid+1,hi,a,b,val);
		segTree[r] = max(segTree[r<<1],segTree[(r<<1)|1]);
	}
}

SEGDATA querySegTree(int r,int lo,int hi,int a,int b) {
	if(lo > b || hi < a) {
		return 0;
	} else if(a <= lo && b >= hi) {
		return segTree[r];
	} else {
		int mid = (lo+hi)>>1;
		return max(querySegTree(r<<1,lo,mid,a,b),querySegTree((r<<1)|1,mid+1,hi,a,b));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		int pt = b % h;
		if(a) {
			updateSegTree(1,1,h,pt,pt,1);
		} else {
			updateSegTree(1,1,h,pt,pt,-1);
		}
		cout << querySegTree(1,1,h,1,h) << "\n";
	}
	return 0;
}
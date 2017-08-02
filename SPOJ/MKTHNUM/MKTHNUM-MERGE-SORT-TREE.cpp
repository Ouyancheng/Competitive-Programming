#include<bits/stdc++.h>
 
using namespace std;
 
#define MSDATA int
#define MAX_N 100005
 
// This library implements a merge sort tree
 
// To change the type of merge sort tree just tweak the defintion of
// MSDATA macro
 
// Variables for merge sort tree
// merge sort tree requires 2^x - 1 space, where 2^x >= 2n.
// But we use 2^x >= 2n+1 where x is the height of the merge sort tree
MSDATA msTreeBase[MAX_N];
vector<MSDATA> sortedMSData[262144];
 
// User-defined variables
int n,q,a,b,c,rk[MAX_N],d[MAX_N],ans;
 
// Pre-condition: r = 1, lo = 1, hi = n
// indexes 1 to N in msTreeBase are already filled
// Post-condition:  Builds the segment tree using indexes 1 to N
void buildMSTree(int r,int lo,int hi) {
	sortedMSData[r].resize(hi-lo+1);
	if(lo==hi) {
		sortedMSData[r][0] = rk[lo];
	} else {
		buildMSTree(r<<1,lo,(lo+hi)>>1);
		buildMSTree((r<<1)|1,((lo+hi)>>1)+1,hi);
		merge(sortedMSData[r<<1].begin(),sortedMSData[r<<1].end(),
			sortedMSData[(r<<1)|1].begin(),sortedMSData[(r<<1)|1].end(),
			sortedMSData[r].begin());
	}
}
 
// Pre-condition: r = 1, lo = 1, hi = n, a = left bound, b = right bound
// Post-condition: performs a query on the range [a,b]
int queryMSTree(int r,int lo,int hi,int a,int b,int x) {
	if(lo > b || hi < a) {
		return 0;
	} else if(a <= lo && b >= hi) {
		return lower_bound(sortedMSData[r].begin(),sortedMSData[r].end(),x)-sortedMSData[r].begin();
	} else {
		int mid = (lo+hi)>>1;
		return queryMSTree(r<<1,lo,mid,a,b,x)+queryMSTree((r<<1)|1,mid+1,hi,a,b,x);
	}
}
 
// Helper function for printing the real values of msTreeBase
void printMSTree(int n) {
	for(int i = 1; i <= n; i++) {
		cout << queryMSTree(1,1,n,i,i,0) << " ";
	}
	cout << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> d[i-1];
		msTreeBase[i] = d[i-1];
	}
	sort(d,d+n);
	for(int i = 1; i <= n; i++) {
		rk[i] = (lower_bound(d,d+n,msTreeBase[i])-d) + 1;
	}
	for(int i = 1; i <= n; i++) {
		d[rk[i]] = msTreeBase[i];
	}
	buildMSTree(1,1,n);
	for(int i = 1; i <= q; i++) {
		cin >> a >> b >> c;
		int lo = 1, hi = n;
		while(lo <= hi) {
			int mid = (lo+hi)>>1,res = queryMSTree(1,1,n,a,b,mid);
			if(res+1 > c) {
				hi = mid-1;
			} else {
				ans = mid;
				lo = mid+1;
			}
		}
		cout << d[ans] << "\n";
	}
	return 0;
} 
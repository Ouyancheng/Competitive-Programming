#include<bits/stdc++.h>

using namespace std;

#define ll int
#define MAX_N 60005

// Important! This is a range-sum implementation of segment tree

// To change the type of the segment tree just tweak the defintion of
// ll in front of the segment tree variables

// Variables for segment tree
// Segment tree requires 2^x - 1 space, where 2^x >= 2n-1.
// But we use 2^x - 1 >= 2n+1 where x is the height of the segment tree
ll segTree[131072], segArr[MAX_N];

// User-defined variables
int n,t,k;

// Pre-condition: r = 1, lo = 1, hi = n
// indexes 1 to N in segArr are already filled
// Post-condition:  Builds the segment tree using indexes 1 to N
void buildSegTree(int r,int lo,int hi) {
	if(lo==hi) {
		segTree[r] = segArr[lo];
	} else {
		buildSegTree(r<<1,lo,(lo+hi)>>1);
		buildSegTree((r<<1)|1,((lo+hi)>>1)+1,hi);
		segTree[r] = segTree[r<<1]&segTree[(r<<1)|1];
	}
}

// Pre-condition: r = 1, lo = 1, hi = n, a = left bound, b = right bound
// Post-condition: performs a query on the range [a,b] 
ll querySegTree(int r,int lo,int hi,int a,int b) {
	if(lo > b || hi < a) {
		return INT_MAX;
	} else if(a <= lo && b >= hi) {
		return segTree[r];
	} else {
		int mid = (lo+hi)>>1;
		return querySegTree(r<<1,lo,mid,a,b)&querySegTree((r<<1)|1,mid+1,hi,a,b);
	}
}

// Helper function for printing the real values of segArr
void printSegTree(int n) {
	for(int i = 1; i <= n; i++) {
		cout << querySegTree(1,1,n,i,i) << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> segArr[i];
			segArr[i+n] = segArr[i];
			segArr[i+2*n] = segArr[i];
		}
		if(k >= (int)ceil(1.0*(n>>1))) k = (int) ceil(1.0*(n>>1));
		buildSegTree(1,1,3*n);
		for (int i = n+1; i <= 2*n; ++i) {
			cout << querySegTree(1,1,3*n,i-k,i+k) << " ";
		}
		cout << "\n";
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define SEGDATA pair<int,int>
#define MAX_N 200005

// Important! This is a range-sum implementation of segment tree

// To change the type of the segment tree just tweak the defintion of
// SEGDATA macro

// Variables for segment tree
// Segment tree requires 2^x - 1 space, where 2^x >= 2n.
// But we use 2^x >= 2n+1 where x is the height of the segment tree
SEGDATA segTree[524288]; int segArr[MAX_N];

// User-defined variables
int n,q,x,y,d[MAX_N];
char c;
pair<int,int> nil;

// Pre-condition: r = 1, lo = 1, hi = n
// indexes 1 to N in segArr are already filled
// Post-condition:  Builds the segment tree using indexes 1 to N
void buildSegTree(int r,int lo,int hi) {
	if(lo==hi) {
		segTree[r] = make_pair(segArr[lo],lo);
	} else {
		buildSegTree(r<<1,lo,(lo+hi)>>1);
		buildSegTree((r<<1)|1,((lo+hi)>>1)+1,hi);
		segTree[r] = max(segTree[r<<1],segTree[(r<<1)|1]);
	}
}

// Pre-condition: r = 1, lo = 1, hi = n, a = left bound, b = right bound
// val = new value
// Post-condition: updates the range [a,b] by setting each of their values to val
void updateSegTree(int r,int lo,int hi,int a,int b,int val) {
	if(lo > b || hi < a) {
		return;
	} else if(a <= lo && b >= hi) {
		segTree[r].first = val;
	} else {
		int mid = (lo+hi)>>1;
		updateSegTree(r<<1,lo,mid,a,b,val);
		updateSegTree((r<<1)|1,mid+1,hi,a,b,val);
		segTree[r] = max(segTree[r<<1],segTree[(r<<1)|1]);
	}
}

// Pre-condition: r = 1, lo = 1, hi = n, a = left bound, b = right bound
// Post-condition: performs a query on the range [a,b] 
SEGDATA querySegTree(int r,int lo,int hi,int a,int b) {
	if(lo > b || hi < a) {
		return nil;
	} else if(a <= lo && b >= hi) {
		return segTree[r];
	} else {
		int mid = (lo+hi)>>1;
		SEGDATA res1 = querySegTree(r<<1,lo,mid,a,b);
		SEGDATA res2 = querySegTree((r<<1)|1,mid+1,hi,a,b);
		return max(res1,res2);
	}
}

// Helper function for printing the real values of segArr
void printSegTree(int n) {
	for(int i = 1; i <= n; i++) {
		cout << querySegTree(1,1,n,i,i).first << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> d[i+1];
		segArr[i+1] = d[i+1];
	}
	buildSegTree(1,1,n);
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> c >> x >> y;
		if(c == 'Q') {
			int i1 = querySegTree(1,1,n,x,y).second;
			updateSegTree(1,1,n,i1,i1,0);
			int i2 = querySegTree(1,1,n,x,y).second;
			updateSegTree(1,1,n,i1,i1,d[i1]);
			cout << 0LL + d[i1] + d[i2] << "\n";
		} else {
			d[x] = y;
			updateSegTree(1,1,n,x,x,y);
		}
	}
	return 0;
}
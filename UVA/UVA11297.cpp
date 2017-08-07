#include<bits/stdc++.h>

using namespace std;

// This library implements a 2-D Segment Tree with range update
//
// *USAGE:
//
// To change the type of the segment tree just tweak the defintion of
// the SEGTYPE variable. Certain default values may have to be changed as well.
//
// MAX_N: If maximum number of rows in 2-D range is N, set this to >= N+1
// MAX_M: If maximum number of cols in 2-D range is M, set this to >= M+1
// MAX_NS: find x such that 2^x - 1 >= 2n+1. Then set this to 2^x (n is max number of rows)
// MAX_MS: find x such that 2^x - 1 >= 2m+1. Then set this to 2^x (m is max number of cols)
// SEGTYPE: set this to the type of data that you wish to store in the segment tree
// Do not modify the rest of the macros!
//
// Read the given values into "segArr" variable
// Call the build2ST() macro to build the segment tree
// Now use query2ST() and update2ST() to update and query the segment tree
//
// *OPERATIONS:
// Range Query: Query for values within a 2d range [(lo1,hi1) to (lo2,hi2)] --> O(logn*logm) (See remarks)
// Range Update: Updates the values over a 2d range [(lo1,hi1) to (lo2,hi2)] --> O(logn*logm) (See remarks)
//
// *TIME AND SPACE COMPLEXITY:
// Time-complexity: O(nlogn*mlogm) for construction of segment tree.
// Space-complexity: O(nlogn*mlogm) for construction of segment tree.
//
// *REMARKS:
// Note that all arrays are 1-indexed
// There is no return value for querySegTree (which is called by query2ST), in order to compute the desired-
// value, we have to use an answer variable inside the terminating block for the query (there is a comment in that block)
// Remember to change all update functions if you wish to compute a new property in a segment tree node

#define MAX_N 505
#define MAX_M 505
#define MAX_NS 1024
#define MAX_MS 1024
#define SEGTYPE int
#define query2ST(lo1,hi1,lo2,hi2) querySegTree(1,1,1,1,n,n,lo1,hi1,lo2,hi2)
#define update2ST(lo1,hi1,lo2,hi2,val) updateSegTree(1,1,1,1,n,n,lo1,hi1,lo2,hi2,val)
#define build2ST() buildSegTree(1,1,1,1,n,n)

struct SegData {
	SEGTYPE mx,mn,sum;

	SegData(): mx(INT_MIN), mn(INT_MAX), sum(0) {}
	SegData(SEGTYPE a,SEGTYPE b,SEGTYPE c) {
		mx = a, mn = b, sum = c;
	}
};

// Variables for segment tree
// Segment tree requires (2^x - 1)^2 space, where 2^x >= 2n-1.
// But we use 2^x - 1 >= 2n+1 where x is the height of the segment tree
SegData segTree[MAX_NS][MAX_MS]; int segArr[MAX_N][MAX_M];
SEGTYPE lz[MAX_NS][MAX_MS]; bool old[MAX_NS][MAX_MS];
SegData NIL = SegData(); // dummy node. Do not remove!

// User-defined variables
int n,q,x,xx,y,yy;
SEGTYPE tmp,resMax,resMin;
char c;

// Helper for updateSegTree function
// Pre-condition: r1 = 1,r2 = 2, lo1 = upper row, hi1 = upper col, lo2 = lower row, hi2 = lower col
// Post-condition: performs lazy update on 2-d range [(lo1,hi1) to (lo2,hi2)]
void lazyUpdate(int r1,int r2,int lo1,int hi1,int lo2,int hi2) {
	if(old[r1][r2]) {
		segTree[r1][r2].mx = lz[r1][r2];
		segTree[r1][r2].mn = lz[r1][r2];
		//segTree[r1][r2].sum = 1LL*(hi2-hi1+1)*(lo2-lo1+1)*lz[r1][r2];

		if(lo1 != lo2 || hi1 != hi2) {
			old[r1<<1][r2<<1] = old[r1<<1][(r2<<1)|1] =
			old[(r1<<1)|1][r2<<1] = old[(r1<<1)|1][(r2<<1)|1] = 1;

			lz[r1<<1][r2<<1] = lz[r1<<1][(r2<<1)|1] =
			lz[(r1<<1)|1][r2<<1] = lz[(r1<<1)|1][(r2<<1)|1] = lz[r1][r2];
		}
		old[r1][r2] = lz[r1][r2] = 0;
	}
}

// Pre-condition: r1 = 1,r2 = 2, lo1 = upper row, hi1 = upper col, lo2 = lower row, hi2 = lower col
// val = value to update the range [(lo1,hi1) to (lo2,hi2)]
// Post-condition: performs lazy update on 2-d range [(lo1,hi1) to (lo2,hi2)]
void updateNode(int r1,int r2,int lo1,int hi1,int lo2,int hi2,SEGTYPE val) {
	segTree[r1][r2].mx = val;
	segTree[r1][r2].mn = val;
	//segTree[r1][r2].sum = 1LL*(hi2-hi1+1)*(lo2-lo1+1)*val;

	if(lo1 != lo2 || hi1 != hi2) {
		old[r1<<1][r2<<1] = old[r1<<1][(r2<<1)|1] =
		old[(r1<<1)|1][r2<<1] = old[(r1<<1)|1][(r2<<1)|1] = 1;
		lz[r1<<1][r2<<1] = lz[r1<<1][(r2<<1)|1] =
		lz[(r1<<1)|1][r2<<1] = lz[(r1<<1)|1][(r2<<1)|1] = lz[r1][r2];
	}
}

// Pre-condition: r1 = 1,r2 = 2, lo1 = upper row, hi1 = upper col, lo2 = lower row, hi2 = lower col
// Post-condition: calculates the data for the current node from its children's data
void saveResults(int r1,int r2,int lo1,int hi1,int lo2,int hi2) {
	SegData s1 = NIL, s2 = NIL, s3 = NIL, s4 = NIL;

	if(!(lo1 > (lo1+lo2)>>1 || hi1 > (hi1+hi2)>>1))
		s1 = segTree[r1<<1][r2<<1];
	if(!(lo1 > (lo1+lo2)>>1 || ((hi1+hi2)>>1)+1 > hi2))
		s2 = segTree[r1<<1][(r2<<1)|1];
	if(!(((lo1+lo2)>>1)+1 > lo2 || hi1 > (hi1+hi2)>>1))
		s3 = segTree[(r1<<1)|1][r2<<1];
	if(!(((lo1+lo2)>>1)+1 > lo2 || ((hi1+hi2)>>1)+1 > hi2))
		s4 = segTree[(r1<<1)|1][(r2<<1)|1];

	segTree[r1][r2].mx = max(s1.mx,max(s2.mx,max(s3.mx,s4.mx)));
	segTree[r1][r2].mn = min(s1.mn,min(s2.mn,min(s3.mn,s4.mn)));
	//segTree[r1][r2].sum = 0LL + s1.sum + s2.sum + s3.sum + s4.sum;
}

// Pre-condition: r1 = 1,r2 = 2, lo1 = upper row, hi1 = upper col, lo2 = lower row, hi2 = lower col
// Range [(1,1),(n,n)] in segArr is already filled
// Post-condition:  Builds the segment tree using the populated range
void buildSegTree(int r1,int r2,int lo1,int hi1,int lo2,int hi2) {
	if(lo1 > lo2 || hi1 > hi2) return;
	if(lo1 == lo2 && hi1 == hi2) {
		segTree[r1][r2].mx = segArr[lo1][hi1];
		segTree[r1][r2].mn = segArr[lo1][hi1];
		segTree[r1][r2].sum = segArr[lo1][hi1];
	} else {
		buildSegTree(r1<<1,r2<<1,lo1,hi1,(lo1+lo2)>>1,(hi1+hi2)>>1);
		buildSegTree(r1<<1,(r2<<1)|1,lo1,((hi1+hi2)>>1)+1,(lo1+lo2)>>1,hi2);
		buildSegTree((r1<<1)|1,r2<<1,((lo1+lo2)>>1)+1,hi1,lo2,(hi1+hi2)>>1);
		buildSegTree((r1<<1)|1,(r2<<1)|1,((lo1+lo2)>>1)+1,((hi1+hi2)>>1)+1,lo2,hi2);
		saveResults(r1,r2,lo1,hi1,lo2,hi2);
	}
}

// Pre-condition: r = 1, lo = 1, hi = n, a = left bound, b = right bound
// val = new value
// Post-condition: updates the range [(lo1,hi1) to (lo2,hi2)] by setting each of their values to val
void updateSegTree(int r1,int r2,int lo1,int hi1,int lo2,int hi2,int a1,int b1,int a2,int b2,SEGTYPE val) {
	if(a1 > lo2 || b1 > hi2 || a2 < lo1 || b2 < hi1) return;
	if(lo1 != lo2 || hi1 != hi2) lazyUpdate(r1,r2,lo1,hi1,lo2,hi2);
	if(a1 <= lo1 && b1 <= hi1 && a2 >= lo2 && b2 >= hi2) {
		updateNode(r1,r2,lo1,hi1,lo2,hi2,val);
	} else {
		updateSegTree(r1<<1,r2<<1,lo1,hi1,(lo1+lo2)>>1,(hi1+hi2)>>1,a1,b1,a2,b2,val);
		updateSegTree(r1<<1,(r2<<1)|1,lo1,((hi1+hi2)>>1)+1,(lo1+lo2)>>1,hi2,a1,b1,a2,b2,val);
		updateSegTree((r1<<1)|1,r2<<1,((lo1+lo2)>>1)+1,hi1,lo2,(hi1+hi2)>>1,a1,b1,a2,b2,val);
		updateSegTree((r1<<1)|1,(r2<<1)|1,((lo1+lo2)>>1)+1,((hi1+hi2)>>1)+1,lo2,hi2,a1,b1,a2,b2,val);
		saveResults(r1,r2,lo1,hi1,lo2,hi2);
	}
}


// Pre-condition: r1 = 1,r2 = 2, lo1 = upper row, hi1 = upper col, lo2 = lower row, hi2 = lower col
// Post-condition: performs query on the range [(lo1,hi1) to (lo2,hi2)]
void querySegTree(int r1,int r2,int lo1,int hi1,int lo2,int hi2,int a1,int b1,int a2,int b2) {
	if(a1 > lo2 || b1 > hi2 || a2 < lo1 || b2 < hi1) return;
	if(lo1 != lo2 || hi1 != hi2) lazyUpdate(r1,r2,lo1,hi1,lo2,hi2);
	if(a1 <= lo1 && b1 <= hi1 && a2 >= lo2 && b2 >= hi2) {
		//Get the answer to your query here
		//tmp = max(tmp,segTree[r1][r2].mx); // Uncomment this line to use printSegTree
		resMax = max(resMax,segTree[r1][r2].mx);
		resMin = min(resMin,segTree[r1][r2].mn);
	} else {
		querySegTree(r1<<1,r2<<1,lo1,hi1,(lo1+lo2)>>1,(hi1+hi2)>>1,a1,b1,a2,b2);
		querySegTree(r1<<1,(r2<<1)|1,lo1,((hi1+hi2)>>1)+1,(lo1+lo2)>>1,hi2,a1,b1,a2,b2);
		querySegTree((r1<<1)|1,r2<<1,((lo1+lo2)>>1)+1,hi1,lo2,(hi1+hi2)>>1,a1,b1,a2,b2);
		querySegTree((r1<<1)|1,(r2<<1)|1,((lo1+lo2)>>1)+1,((hi1+hi2)>>1)+1,lo2,hi2,a1,b1,a2,b2);
	}
}

// Helper function for printing the real values of segArr
void printSegTree(int n) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			tmp = INT_MIN;
			querySegTree(1,1,1,1,n,n,i,j,i,j);
			cout << tmp << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> segArr[i][j];
		}
	}
	build2ST();	

	cin >> q;
	for(int i = 1; i <= q; i++) {
		cin >> c;
		if(c == 'q') {
			cin >> x >> y >> xx >> yy;
			resMax = INT_MIN ,resMin = INT_MAX;
			query2ST(x,y,xx,yy);
			cout << resMax << " " << resMin << "\n";
		} else {
			cin >> x >> y >> xx;
			update2ST(x,y,x,y,xx);
		}
	}
	return 0;
}

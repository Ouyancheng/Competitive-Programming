#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N 100005

//user-defined varaibles
int arr[MAX_N], n, q, a, b, c;

// Important! This is a range-sum implementation of segment tree

// To change the type of the segment tree just tweak the defintion of
// ll in front of the segment tree variables

// Variables for segment tree
// Segment tree requires 2^x - 1 space, where 2^x >= 2n-1.
// But we use 2^x - 1 >= 2n+1 where x is the height of the segment tree
ll segTree[262143], segArr[MAX_N], lz[262143];

// Pre-condition: r = 1, lo = 1, hi = MAX_N-1
// indexes 1 to N in segArr are already filled
// Post-condition:  Builds the segment tree using indexes 1 to N
void buildSegTree(int r,int lo,int hi) {
	if(lo==hi) {
		segTree[r] = segArr[lo];
	} else {
		buildSegTree(r<<1,lo,(lo+hi)>>1);
		buildSegTree((r<<1)|1,((lo+hi)>>1)+1,hi);
		segTree[r] = segTree[r<<1]+segTree[(r<<1)|1];
	}
}

// Pre-condition: r = 1, lo = 1, hi = MAX_N-1, a = left bound, b = right bound
// val = new value
// Post-condition: updates the range [a,b] by adding val to each of their values
void updateSegTree(int r,int lo,int hi,int a,int b,ll val) {
	if(lz[r]) {
		segTree[r] += (hi-lo+1) * lz[r];
		if(lo != hi) {
			lz[r<<1] += lz[r];
			lz[(r<<1)|1] += lz[r];
		}
		lz[r] = 0;
	}
	if(lo > b || hi < a) {
		return;
	} else if(a <= lo && b >= hi) {
		segTree[r] += (hi-lo+1) * val;
		if(lo != hi) {
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

// Pre-condition: r = 1, lo = 1, hi = MAX_N-1, a = left bound, b = right bound
// Post-condition: performs a query on the range [a,b] 
ll querySegTree(int r,int lo,int hi,int a,int b) {
	if(lz[r]) {
		segTree[r] += (hi-lo+1) * lz[r];
		if(lo != hi) {
			lz[r<<1] += lz[r];
			lz[(r<<1)|1] += lz[r];
		}
		lz[r] = 0;
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

// Helper function for printing the real values of segArr
void printSegTree(int n) {
	for(int i = 1; i <= n; i++) {
		cout << querySegTree(1,1,n,i,i) << " ";
	}
	cout << endl;
}

ll query(int l,int r,int k) {
    return querySegTree(1,1,n,l,r)-querySegTree(1,1,n,l-k-1,r-k-1);
}

int main(void) {
	scanf("%d %d",&n,&q);
	for(int i = 1; i <= n; i++) {
	    scanf("%d",&segArr[i]);
	    arr[i] = segArr[i];
	}
	for(int i = 1; i <= n; i++) {
		segArr[i] += segArr[i-1];
	}
	buildSegTree(1,1,n);
	for(int i = 1; i <= q; i++) {
	    scanf("%d",&a);
	    if(a == 1) {
	        scanf("%d %d %d",&a,&b,&c);
	        printf("%lld\n",query(a,b,c));
	    } else {
	        scanf("%d %d",&a,&b);
	        updateSegTree(1,1,n,a,n,b-arr[a]);
	        arr[a] = b;
	    }
	}
	return 0;
}

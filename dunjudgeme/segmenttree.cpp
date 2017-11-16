#include "segmenttree.h"

using namespace std;

#include <cmath>
#define SEGDATA int
#define MAX_N 100005

SEGDATA segTree[262144];
int seg_size;


void updateSegTree(int r,int lo,int hi,int a,int b,SEGDATA val) {
	if(lo > a || hi < a) return;
	if(a <= lo && b >= hi) {
		segTree[r] = val;
		return;
	}
	int mid = (lo+hi)>>1;
	updateSegTree(r<<1,lo,mid,a,b,val);
	updateSegTree((r<<1)|1,mid+1,hi,a,b,val);
	segTree[r] = min(segTree[r<<1],segTree[(r<<1)|1]);
}

SEGDATA querySegTree(int r,int lo,int hi,int a,int b) {
	if(lo > b || hi < a) {
		return (int) 1e9+5;
	} else if(a <= lo && b >= hi) {
		return segTree[r];
	} else {
		int mid = (lo+hi)>>1;
		return min(querySegTree(r<<1,lo,mid,a,b),querySegTree((r<<1)|1,mid+1,hi,a,b));
	}
}

void init(int N) {
	seg_size = N;
	return;
}

void update(int P, int V) {
	updateSegTree(1,0,seg_size-1,P,P,V);
}

int query(int A, int B) {
	return querySegTree(1,0,seg_size-1,A,B);
}
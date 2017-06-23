#include<bits/stdc++.h>
 
using namespace std;
 
// This is a range-sum implementation of persistent segment tree that suppports-
// Point Updates and Range Queries
// Strictly speaking, memory complexity of PST is (Memory of ST)+UlogE where U is no. of updates
// To change the type of the segment tree just tweak the defintion of
// ll in front of the array variables
 
// MAX_N: if maximum number of elements in the given array is N, set this to N+1
// MAX_U: if maximum number of update operations is U, set this to U+1
// MAX_E: find 2^x such that 2^x >= 2n+1. Then set this to 2^x+1
// MAX_LOGE: set this to ceil(MAX_E)
 
// Segment tree requires 2^x - 1 space, where 2^x >= 2n-1.
// But we use 2^x - 1 >= 2n+1 where x is the height of the segment tree
// Important: Note that all arrays are 1-indexed
 
#define MAX_N 100001
#define MAX_U 100001
#define MAX_E 262144
#define MAX_LOGE 18
 
int st[MAX_U+1], arr[MAX_N], L[MAX_E+MAX_U*MAX_LOGE], R[MAX_E+MAX_U*MAX_LOGE];
int data[MAX_E+MAX_U*MAX_LOGE];
int NODES_COUNT;
 
// Pre-condition: r = 1, lo = 1, hi = N
// indexes 1 to N in array are already filled
// Post-condition:  Builds the segment tree using indexes 1 to N
void build(int r,int lo,int hi) {
	if(lo==hi) {
		data[r] = arr[lo];
	} else {
		L[r] = ++NODES_COUNT;
		R[r] = ++NODES_COUNT;
		build(L[r],lo,(lo+hi)>>1);
		build(R[r],((lo+hi)>>1)+1,hi);
		data[r] = data[L[r]]+data[R[r]];
	}
}
 
// Pre-condition: r = id of new root, lo = 1, hi = N,
// pre = id of original root
// idx = index of the element to modify
// val = new value
// Post-condition: updates the element at idx by setting its value to val
void update(int r,int lo,int hi,int pre,int idx,int val) {
	if(lo > idx || hi < idx) {
		return;
	} else if(lo == hi) {
		data[r] = val;
	} else {
		int mid = (lo+hi)>>1;
		if(idx <= mid) {
			R[r] = R[pre];
			L[r] = ++NODES_COUNT;
			update(L[r],lo,mid,pre[L],idx,val);
		} else {
			L[r] = L[pre];
			R[r] = ++NODES_COUNT;
			update(R[r],mid+1,hi,pre[R],idx,val);
		}
		data[r] = data[L[r]]+data[R[r]];
	}
}
 
// Pre-condition: r = 1, lo = 1, hi = N, a = left bound, b = right bound
// Post-condition: performs a query on the range [a,b] 
int query(int r,int pre,int lo,int hi,int k) {
	if(lo == hi) {
		return lo;
	}
	int mid = (lo+hi)>>1;
	int e = data[L[r]]-data[L[pre]];
	if(e >= k) {
		return query(L[r],L[pre],lo,mid,k);
	} else {
		return query(R[r],R[pre],mid+1,hi,k-e);
	}
}
 
int nquery(int r,int lo,int hi,int a,int b) {
	if(lo > b || hi < a) return 0;
	if(lo == hi) {
		return data[r];
	}
	int mid = (lo+hi)>>1;
	if(a <= mid) {
		return nquery(L[r],lo,mid,a,b);
	} else {
		return nquery(R[r],mid+1,hi,a,b);
	}
}
 
// Helper function for printing the real values of arr
void printST(int n,int par) {
	for(int i = 1; i <= n; i++) {
		cout << nquery(par,1,n,i,i) << " ";
	}
	cout << endl;
}
 
int n,q,a,b,k,org[MAX_N];
map<int,int> m,rm;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> org[i];
		m[org[i]];
	}
	int rank = 1;
	for(auto p : m) {
		m[p.first] = rank;
		rm[rank++] = p.first;
	}
	st[0] = ++NODES_COUNT;
	build(st[0],1,n);
		
	for(int i = 1; i <= n; i++) {
		st[i] = ++NODES_COUNT;
		update(st[i],1,n,st[i-1],m[org[i]],1);
	}
	
	for(int i = 1; i <= q; i++) {
		cin >> a >> b >> k;
		cout << rm[query(st[b],st[a-1],1,n,k)] << "\n";
	}
	
	return 0;
} 
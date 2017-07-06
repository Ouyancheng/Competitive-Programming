#include<bits/stdc++.h>

// This is a range-update range-query implementation of 1-d segment tree

// Usage:
// MAX_N: Maximum number of elements (starting from 1)

// Read the number of expected elements into variable n from stdin
// Remember that fenwick trees are 1-based!
// Only use the updateFT() function to update/insert elements into the fenwick tree

// Operations:
// Range-Query (Prefix-Sum): queryFT() --> O(logn)
// Range-Update: updateFT() --> O(logn)

// Time and Space Complexity
// O(nlogn) for building the fenwick tree (because of updating)
// O(n) space complexity

using namespace std;

#define ll long long
#define MAX_N 100005

// Variables for fenwick tree
ll f1[MAX_N], f2[MAX_N];

// User defined variables: n is required by fenwick tree
int t,n,q;
ll a,b,c;

// Pre-condition:
// i: index to query (1-indexed)
// f: array of integers representing fenwick tree
// Post-condition:
// Returns the cumulative sum of all elements
// in the range [1,i] in the the array f1
ll queryFTHelper(int i,ll f[]) {
	int c = i;
	ll ans = 0;
	while(c) {
		ans += f[c];
		c -= c & -c;
	}
	return ans;
}

// Pre-condition:
// d: value to add to index i (1-indexed)
// i: index to add to
// f: array of integers representing fenwick tree
// Post-condition:
// Adds d to the element at index i
// in the array f1
void updateFTHelper(ll d,int i,ll f[]) {
	int c = i;
	while(c <= n) {
		f[c] += d;
		c += c & -c;
	}
}

// Pre-condition:
// i: index to query (1-indexed)
// Post-condition:
// Returns the cumulative sum of all elements
// in the range [1,i] in the the array f1
ll queryFT(int i) {
	return (i >= 0) ? queryFTHelper(i,f1)*i-queryFTHelper(i,f2) : 0;
}

// Pre-condition:
// d: value to add to index i (1-indexed)
// lo: lower bound query range (inclusive)
// hi: upper bound of query range (inclusive)
// If hi is not stated, the operation becomes a point update
// Post-condition:
// "Adds" d to the element to indexes in [lo,hi]
// in the array f1 (Actual value can only be printed by printFT())
void updateFT(ll d,int lo,int hi=0) {
	hi = hi ? hi : lo;
	updateFTHelper(d,lo,f1);
	updateFTHelper(-d,hi+1,f1);
	updateFTHelper(d*(lo-1),lo,f2);
	updateFTHelper(-d*hi,hi+1,f2);
}

void printFT(int n) {
	for(int i = 1; i <= n; i++) {
		cout << queryFT(i)-queryFT(i-1) << " ";
	}
	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		fill(f1,f1+n+1,0);
		fill(f2,f2+n+1,0);
		cin >> n >> q;
		for(int j = 1; j <= q; j++) {
			cin >> a;
			if(!a) {
				cin >> a >> b >> c;
				updateFT(c,a,b);
			} else {
				cin >> a >> b;
				cout << queryFT(b)-queryFT(a-1) << "\n";
			}
		}
	}
	return 0;
}

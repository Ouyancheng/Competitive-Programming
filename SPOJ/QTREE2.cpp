#include<bits/stdc++.h>

using namespace std;

// This library implements an algorithm to find Lowest Common Ancestor (LCA) of nodes in a general tree
// It requires O(N*ceil(logN)) space and time to precompute sparse table.
// After that, it can answer LCA(a,b) queries in O(logn) time using binary lifting technique.
//
// Usage:
//
// MAX_V: >= N
// LOG_V >= floor(log2(N)) + 1
//
// Build the adjacency list for the given graph by calling addLCAEdge
// Then call buildLCATree() to perform precomputation
// To answer LCA queries, call the LCA(a,b) function
//
// Operations:
// Find LCA - LCA(a,b): finds LCA of 2 nodes in a tree -> O(logN)
// Find Kth ancestor - kthAncestor(a,k): finds kth ancestor of node in a tree -> O(logN) (See remarks)
// Find Kth node on path - kthNodeOnPath(a,b,k): Finds the kth node on path from a to b -> O(logN) (See remarks)
//
// Space-complexity:
// O(nlogn) because of sparse table
//
// Remarks:
// This library assumes that all elements are 0-indexed
// 0-th ancestor is the parent of the node in the tree, invalid ancestors are returned as -1
// kthNodeOnPath assumes that k starts from 1, returns -1 if invalid

#define MAX_V 10005
#define LOG_V 15

// Variables for LCA
int v,logv,c;
vector< pair<int,int> > LCAGraph[MAX_V];
int lvl[MAX_V], par[MAX_V], ST[MAX_V][LOG_V], sum[MAX_V];

// user-defined variables
int a,b,k,t;
string s;

void addLCAEdge(int u,int v,int w=0) {
	LCAGraph[u].emplace_back(v,w);
	LCAGraph[v].emplace_back(u,w);
}

int LCA(int a,int b) {
	if(lvl[a] < lvl[b]) swap(a,b);

	for(int i = floor(log2(lvl[a])); i >= 0; i--) {
		if(lvl[a] - (1 << i) >= lvl[b]) {
			a = ST[a][i];
		}
	}
	if(a == b) return a;
	for(int i = logv-1; i >= 0; i--) {
		if(ST[a][i] != -1 && ST[a][i] != ST[b][i]) {
			a = ST[a][i], b = ST[b][i];
		}
	}
	return par[a];
}

int kthAncestor(int a,int k=0) {
	int pos = lvl[a]-k-1;
	for(int i = floor(log2(lvl[a])); i >= 0; i--) {
		if(a == -1) break;
		if(lvl[a] - (1 << i) >= pos) {
			a = ST[a][i];
		}
	}
	return a;
}

int kthNodeOnPath(int a,int b,int k) {
	if(k < 2) return a;
	int u = LCA(a,b);
	int d1 = lvl[a] - lvl[u];
	int d2 = lvl[b] - lvl[u];
	if(d1+1 >= k) {
		return kthAncestor(a,k-2);
	} else if(d2 >= k-d1-1) {
		if(d2-(k-d1-1)-1 < 0) return b;
		return kthAncestor(b,d2-(k-d1-1)-1);
	}
	return -1;
}

int DIST(int a,int b) {
	int u = LCA(a,b);
	return sum[a] + sum[b] - 2 * sum[u];
}

void buildLCATree(int cur=0,int anc=-1,int depth=1,int total=0) {
	lvl[cur] = depth;
	par[cur] = ST[cur][0] = anc;
	sum[cur] = total;
	for(int i = 1; (1 << i) < lvl[cur]; i++) {
		ST[cur][i] = ST[ST[cur][i-1]][i-1];
	}
	for(int i = 0; i < (int) LCAGraph[cur].size(); i++) {
		if(LCAGraph[cur][i].first != anc) {
			buildLCATree(LCAGraph[cur][i].first,cur,depth+1,total+LCAGraph[cur][i].second);
		}
	}
}

void resetLCA() {
	fill(LCAGraph,LCAGraph+v,vector< pair<int,int> >());
	for(int i = 0; i < v; i++) {
		for(int j = 0; j <= logv-1; j++) {
			ST[i][j] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> v;
		logv = floor(log2(v)) + 1;
		resetLCA();
		for(int i = 0; i < v-1; i++) {
			cin >> a >> b >> c;
			a--, b--;
			addLCAEdge(a,b,c);
		}
		buildLCATree();
		while(cin >> s && s[1] != 'O') {
			cin >> a >> b;
			a--,b--;
			if(s[0] == 'D') {
				cout << DIST(a,b);
			} else {
				cin >> k;
				cout << kthNodeOnPath(a,b,k)+1;
			}
			cout << "\n";
		}
	}
	return 0;
}
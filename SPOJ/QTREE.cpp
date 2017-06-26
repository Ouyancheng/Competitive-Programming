#include<bits/stdc++.h>
 
/* Library to perform heavy-light decomposition on general trees */
// To use this library, set the macro MAX_N >= n + 1 and LOG_N >= LOG(n+1)
// Remember to set the segment tree size accordingly
// Call resetHLD() to initialize the HLD data structures
// Then call addHLDEdges to add edges to the HLD tree
// Call the following functions in order:
// buildLCATree(), HLD(), buildSegTree() to perform the HLD on the given tree
// Root for LCATree and HLD must be the same
// This library assumes that elements are all 1-indexed
// All edge costs are also assumed to be non-negative 32-bit signed integers
// Otherwise, appropriate invalid values must be set for invalid segment tree ranges-
// and the w variable in the HLDQuery() paramter
// If 64-bit signed integers are desired, user needs to tweak the relevant-
// segment tree and HLD variables and functions
// The given graph must be a TREE
// Operations:
// HLDQuery: queries a certain property of edges in the path from a to b --> O(log^2(n))
// To change the queried property, modify the HLDQuery function and the-
// segment tree property
// HLDUpdate: updates the weight/cost of a given edge --> O(log(n))
// Time-complexity: O(nlogn) due to construction of sparse table for LCA queries
// Space-complexity: O(nlogn) --> due to construction of sparse table for LCA queries
 
using namespace std;
 
#define MAX_N 10005
#define LOG_N 14
 
// Variables for HLD algorithm
int ssz[MAX_N], pos[MAX_N], id[MAX_N], head[MAX_N], chainlen[MAX_N];
vector< vector< pair<int,int> > > tree;
int ptr,segpos;
 
// Variables for segment tree
// Segment tree requires 2^x - 1 space, where 2^x >= 2n-1.
// But we use 2^x - 1 >= 2n+1 where x is the height of the segment tree
int segmentTree[32768], segArr[MAX_N];
 
// Variables for LCA algorithm
int eui = 1;
int lvl[2*MAX_N], par[MAX_N], euler[2*MAX_N], occ[MAX_N], ST[2*MAX_N][LOG_N];
 
// User defined variables
vector< pair<int,int> >edges;
int n,a,b,c,t;
string s;
 
 
///////////////////////////////////////// Start of LCA functions /////////////////////////////////////////////
void computeSparseTable() {
	for(int i = 1; i <= eui; i++) {
		ST[i][0] = i;
	}
	for(int j = 1; (1 << j) <= eui; j++) {
		for(int i = 1; (i + (1 << j) - 1) <= eui; i++) {
			if(lvl[ST[i][j-1]] <= lvl[ST[i+(1<<(j-1))][j-1]]) {
				ST[i][j] = ST[i][j-1];
			} else {
				ST[i][j] = ST[i+(1<<(j-1))][j-1];
			}
		}
	}
}
 
int rmq(int a,int b) {
	int k = (int) log2(b-a+1);
	if(lvl[ST[a][k]] <= lvl[ST[b-(1<<k)+1][k]]) {
		return ST[a][k];
	} else {
		return ST[b-(1<<k)+1][k];
	}
}
 
int LCA(int a,int b) {
	int x = occ[a], y = occ[b];
	if(x > y) swap(x,y);
	return euler[rmq(x,y)];
}
 
void dfslvl(int cur=1,int pre=0,int depth=1) {
	ssz[cur] = 1;
	occ[cur] = eui;
	par[cur] = pre;
	euler[eui] = cur;
	lvl[eui++] = depth;
	vector< pair<int,int> > adj = tree[cur];
	int s1 = (int) adj.size();
	for(int i = 0; i < s1; i++) {
		pair<int,int> pp = adj[i];
		int v = pp.first;
		if(v != pre) {
			dfslvl(v,cur,depth+1);
			ssz[cur] += ssz[v];
			euler[eui] = cur;
			lvl[eui++] = depth;
		}
	}
}
 
void buildLCATree(int u=1) {
	dfslvl(u);
	computeSparseTable();
}
 
/////////////////////////////////////// Start of Segment tree functions ///////////////////////////////////////////
 
// Pre-condition: r = 1, lo = 1, hi = N
// indexes 1 to N in segArr are already filled
// Post-condition:  Builds the segment tree using indexes 1 to N
void buildSegTree(int r,int lo,int hi) {
	if(lo==hi) {
		segmentTree[r] = segArr[lo];
	} else {
		buildSegTree(r<<1,lo,(lo+hi)>>1);
		buildSegTree((r<<1)|1,((lo+hi)>>1)+1,hi);
		segmentTree[r] = max(segmentTree[r<<1],segmentTree[(r<<1)|1]);
	}
}
 
// Pre-condition: r = 1, lo = 1, hi = N, a = left bound, b = right bound
// val = new value
// Post-condition: updates the range [a,b] by setting each of their values to val
void updateSegTree(int r,int lo,int hi,int a,int b,int val) {
	if(lo > b || hi < a) {
		return;
	} else if(a <= lo && b >= hi) {
		segmentTree[r] = val;
	} else {
		int mid = (lo+hi)>>1;
		updateSegTree(r<<1,lo,mid,a,b,val);
		updateSegTree((r<<1)|1,mid+1,hi,a,b,val);
		segmentTree[r] = max(segmentTree[r<<1],segmentTree[(r<<1)|1]);
	}
}
 
// Pre-condition: r = 1, lo = 1, hi = N, a = left bound, b = right bound
// Post-condition: performs a query on the range [a,b] 
int querySegTree(int r,int lo,int hi,int a,int b) {
	if(lo > b || hi < a) {
		return 0;
	} else if(a <= lo && b >= hi) {
		return segmentTree[r];
	} else {
		int mid = (lo+hi)>>1;
		return max(querySegTree(r<<1,lo,mid,a,b),querySegTree((r<<1)|1,mid+1,hi,a,b));
	}
}
///////////////////////////////////////// Start of HLD functions /////////////////////////////////////////////
void HLD(int u=1,int p=0,int w=0,int chead=0) {
	int weight = -1, heavy = u;
	head[id[u]] = (chead ? chead : u);
	pos[u] = ++segpos;
	segArr[pos[u]] = w;
	chainlen[id[u]]++;
	vector< pair<int,int> > adj = tree[u];
	int s1 = (int) adj.size();
	for(int i = 0; i < s1; i++) {
		pair<int,int> pp = adj[i];
		int v = pp.first, wt = pp.second;
		if(v != p && ssz[v] > weight) {
			weight = wt;
			heavy = v;
		}
	}
	if(weight != -1) {
		id[heavy] = id[u];
		HLD(heavy,u,weight,head[id[u]]);
	}
	for(int i = 0; i < s1; i++) {
		pair<int,int> pp = adj[i];
		int v = pp.first, wt = pp.second;
		if(v != p && v != heavy) {
			id[v] = ++ptr;
			HLD(v,u,wt);
		}
	}
}
 
// Adds undirected edge to HLD tree
// a,b and c represents src,dst and cost respectively
void addHLDEdge(int a,int b,int c) {
	tree[a].push_back(make_pair(b,c));
	tree[b].push_back(make_pair(a,c));
}
 
int queryHLDHelper(int a,int b) {
	if(pos[a] > pos[b]) swap(a,b);
	if(id[a]==id[b]) {
		return querySegTree(1,1,n,pos[a]+1,pos[b]);
	}
	int ans = 0;
	if(head[id[b]]==b) {
		ans = querySegTree(1,1,n,pos[b],pos[b]);
		return max(ans,queryHLDHelper(a,par[b]));
	} else {
		ans = querySegTree(1,1,n,pos[head[id[b]]]+1,pos[b]);
		return max(ans,queryHLDHelper(a,head[id[b]]));
	}
}
 
int queryHLD(int a,int b) {
	int top = LCA(a,b);
	return max(queryHLDHelper(top,a),queryHLDHelper(top,b));
}
 
void updateHLD(int a,int b,int val) {
	int u = (par[a] == b) ? a : b;
	updateSegTree(1,1,n,pos[u],pos[u],val);
}
 
void resetHLD(int n) {
	segpos = ptr = 0;
	eui = 1;
	tree.assign(n+1,vector< pair<int,int> >());
}
 
// Helper function for printing the real values of segArr
void printST(int n) {
	for(int i = 1; i <= n; i++) {
		cout << setw(4) << querySegTree(1,1,n,i,i) << " ";
	}
	cout << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		resetHLD(n);
		edges.clear();
		edges.push_back(make_pair(0,0));
		for(int i = 0; i < n-1; i++) {
			cin >> a >> b >> c;
			addHLDEdge(a,b,c);
			edges.push_back(make_pair(a,b));
		}
		buildLCATree(1);
		HLD(1);
		buildSegTree(1,1,n);
		while(cin >> s && s != "DONE") {
			cin >> a >> b;
			if(s == "QUERY") {
				cout << queryHLD(a,b) << "\n";
			} else {
				updateHLD(edges[a].first,edges[a].second,b);
			}
		}
	}
	return 0;
} 
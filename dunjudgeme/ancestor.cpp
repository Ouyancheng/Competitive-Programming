#include<bits/stdc++.h>

using namespace std;

#define MAX_V 100005
#define LOG_V 18

// Variables for LCA
int v,logv;
vector< pair<int,int> > LCAGraph[MAX_V];
int lvl[MAX_V], par[MAX_V], ST[MAX_V][LOG_V];

// user-defined variables
int a,b,n,q;

void addLCAEdge(int u,int v,int w=0) {
	LCAGraph[u].emplace_back(v,w);
	LCAGraph[v].emplace_back(u,w);
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

void buildLCATree(int cur=0,int anc=-1,int depth=1) {
	lvl[cur] = depth;
	par[cur] = ST[cur][0] = anc;
	for(int i = 1; (1 << i) < lvl[cur]; i++) {
		ST[cur][i] = ST[ST[cur][i-1]][i-1];
	}
	for(int i = 0; i < (int) LCAGraph[cur].size(); i++) {
		if(LCAGraph[cur][i].first != anc) {
			buildLCATree(LCAGraph[cur][i].first,cur,depth+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> v;
	logv = floor(log2(v)) + 1;

	for(int i = 0; i < v; i++) {
		for(int j = 0; j <= logv-1; j++) {
			ST[i][j] = -1;
		}
	}

	for(int i = 0; i < v-1; i++) {
		cin >> a >> b;
		addLCAEdge(a,b);
	}
	buildLCATree();

	cin >> q;

	for(int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << kthAncestor(a,--b) << "\n";
	}
	return 0;
}

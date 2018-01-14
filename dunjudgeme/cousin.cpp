#include "cousins.h"

#include <bits/stdc++.h>

#define MAX_V 200005
#define LOG_V 18

using namespace std;

// Variables for LCA
int v, logv, t, ei;
list<int> LCAGraph[MAX_V];
int lvl[MAX_V], par[MAX_V], ST[MAX_V][LOG_V], in[MAX_V], out[MAX_V], euler[MAX_V];

vector<int> SV[MAX_V];

void buildSV() {
	for(int i = 0; i < v; i++) {
		SV[euler[i]].push_back(i);
	}
}

int querySV(int a,int b,int x) {
	return upper_bound(SV[x].begin(), SV[x].end(), b) - lower_bound(SV[x].begin(), SV[x].end(), a);
}

void addLCAEdge(int u,int v) {
	LCAGraph[u].emplace_back(v);
	LCAGraph[v].emplace_back(u);
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
	in[cur] = t++;
	euler[ei++] = lvl[cur];
	for(int i = 1; (1 << i) < lvl[cur]; i++) {
		ST[cur][i] = ST[ST[cur][i-1]][i-1];
	}
	for(list<int>::iterator i = LCAGraph[cur].begin(); i != LCAGraph[cur].end(); i++) {
		if(*i != anc) {
			buildLCATree(*i,cur,depth+1);
		}
	}
	out[cur] = t - 1;
}

void init(int N, int P[]) {
	v = N;
	for(int i = 1; i < v; i++) {
		addLCAEdge(i, P[i]);
	}
	for(int i = 0; i < v; i++) {
		for(int j = 0; j <= logv-1; j++) {
			ST[i][j] = -1;
		}
	}
	buildLCATree();
	buildSV();
}

int count_cousins(int X, int K) {
	int p = kthAncestor(X, K-1);
	assert(lvl[p] + K == lvl[X]);
	return querySV(in[p], out[p], lvl[X]) - 1;
}

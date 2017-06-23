#include<bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 5000
#define ll long long
 
ll res[MAX_V][MAX_V];
int nei[MAX_V][MAX_V];
int conn[MAX_V];
int lvl[MAX_V];
int vq[MAX_V];
int it[MAX_V];
int src,sink;
int v,e,a,b,c;
 
bool buildLevelGraph(int vertices) {
	fill(lvl,lvl+vertices,-1);
	
	int lo = 0, hi = 0;
	vq[hi++] = src;
	lvl[src] = 0;
 
	while(lo < hi) {
		int u = vq[lo++];
		for(int i = 0; i < conn[u]; i++) {
			int v = nei[u][i];
			if(lvl[v] == -1 && res[u][v] > 0) {
				lvl[v] = lvl[u]+1;
				vq[hi++] = v;
			}
		}
	}
	return lvl[sink] != -1;
}
 
ll pushFlow(int u,ll flow = INT_MAX) {
	if(flow == 0 || u == sink)
		return flow;
 
	for(int &i = it[u]; i < conn[u]; i++) {
		int v = nei[u][i];
		if(lvl[v] == lvl[u] + 1 && res[u][v] > 0) {
			ll bcap = pushFlow(v,min(flow,res[u][v]));
			if(bcap > 0) {
				res[u][v] -= bcap;
				res[v][u] += bcap;
				return bcap;
			}
		}
	}
	return 0;
 
}
 
ll dicnic(int vertices) {
	ll flow = 0;
	while(buildLevelGraph(vertices)) {
		fill(it,it+vertices,0);
		while(ll tmp = pushFlow(src))
			flow += tmp;
	}
	return flow;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> v >> e;
	src = 0, sink = v-1;
 
	for(int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		if(a == b || c == 0) continue;
		a--,b--;
		if(!res[b][a]) {
			nei[a][conn[a]++] = b;
			nei[b][conn[b]++] = a;
		}
		res[a][b] += c;
		res[b][a] += c;
	}
	cout << dicnic(v) << "\n";
	return 0;
} 
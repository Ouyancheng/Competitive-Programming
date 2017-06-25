// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

int color[200005];
int bpos[100005];
int gpos[100005];
queue<int> cur;
vector< vector<int> > graph;
int n,a,b;

void chk (int x) {
	color[x] = 1;
	cur.push(x);
	while(cur.size()) {
		int e = cur.front();
		cur.pop();
		vector<int> adj = graph[e];
		for(int i = 0; i < int(adj.size()); i++) {
			if(color[adj[i]] == 0) {
				color[adj[i]] = ((color[e]==1) ? 2 : 1);
				cur.push(adj[i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	graph.assign(2*n+1,vector<int>());
	for(int i = 1; i <= n; i++) {
		cin >> a >> b;
		bpos[i] = a;
		gpos[i] = b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		graph[2*i-1].push_back(2*i);
		graph[2*i].push_back(2*i-1);
	}
	for(int i = 1; i <= 2*n; i++) if(!color[i]) chk(i);
	for(int i = 1; i <= n; i++) {
		cout << color[bpos[i]] << " " << color[gpos[i]] << endl;
	}
	return 0;
}
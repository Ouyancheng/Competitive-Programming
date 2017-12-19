#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, a, b;
bool vis[maxn];
vector<int> G[maxn];
unordered_set<int> path;
stack<int> s;

bool topo(int u) {
	vis[u] = 1;
	path.insert(u);
	for(int v : G[u]) {
		if(path.find(v) != path.end()) {
			return 0;
		}
		if(!vis[v]) {
			bool t = topo(v);
			if(!t) {
				return 0;
			}
		}
	}
	path.erase(u);
	s.push(u);
	return 1;
}

void work() {
	path.clear();
	while((int) s.size()) {
		s.pop();
	}
	fill(vis, vis+n, 0);

	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			bool b = topo(i);
			if(!b) {
				cout << "IMPOSSIBLE" << "\n";
				return;
			}
		}
	}
	while((int) s.size() > 0) {
		cout << s.top()+1 << "\n";
		s.pop();
	}
}

void addEdge(int a, int b) {
	G[a].push_back(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m) {
		if(!n && !m) {
			break;
		}
		for(int i = 0; i < n; i++) {
			G[i].clear();
		}
		for(int i = 0; i < m; i++) {
			cin >> a >> b;
			addEdge(--a, --b);
		}
		work();
	}
	return 0;
}

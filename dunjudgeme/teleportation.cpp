#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int n, m, a, b, ans, par[maxn];
vector<int> to[maxn];
bool has[maxn], vis[maxn];
unordered_set<int> path;

int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

void dfs(int u) {
	vis[u] = 1;
	path.insert(u);
	for(int i = 0; i < (int) to[u].size(); i++) {
		int v = to[u][i];
		if(find(u) != find(v)) {
			continue;
		}
		if(vis[v] && path.find(v) != path.end()) {
			has[find(v)] = 1;
		}
		if(!vis[v]) {
			dfs(v);
		}
	}
	path.erase(u);
}

void addEdge(int u, int v) {
	to[u].push_back(v);
	par[find(u)] = find(v);
}

int main() {
	scanf("%d %d", &n, &m);

	ans = n;

	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		addEdge(a, b);
	}
	for(int i = 0; i < n; i++) {
		int r = find(i);
		if(has[r]) {
			vis[i] = 1;
		}
		if(!vis[i]) {
			dfs(i);
		}
	}
	for(int i = 0; i < n; i++) {
		int r = find(i);
		if(vis[i] && !has[r]) {
			has[r] = 1;
			ans--;
		}
	}
	printf("%d\n", ans);
}

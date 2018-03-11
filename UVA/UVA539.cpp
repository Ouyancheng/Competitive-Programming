#include<bits/stdc++.h>

using namespace std;

const int maxn = 30;
int n, m, a, b;
vector<int> G[maxn];
bool M[maxn][maxn];

int dfs(int u) {
	int ans = 0;
	for(auto v : G[u]) {
		if(M[u][v]) {
			M[u][v] = M[v][u] = 0;
			ans = max(ans, 1 + dfs(v));
			M[u][v] = M[v][u] = 1;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m) {
		if(!(n || m)) {
			break;
		}
		int ans = 0;
		fill(G, G + n, vector<int>());
		for(int i = 0; i < m; i++) {
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
			M[a][b] = M[b][a] = 1;
		}
		for(int i = 0; i < n; i++) {
			ans = max(ans, dfs(i));
		}
		cout << ans << "\n";
	}
}
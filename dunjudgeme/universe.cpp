#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n, k, a, b;
vector<int> G[maxn];
bool has[maxn];

int dfs(int t, int u = 1, int p = 0) {
	if(t > k) {
		return 0;
	}
	int ans = 0; bool leaf = 1;

	for(int v : G[u]) {
		if(v != p) {
			leaf = 0;
			if(has[v]) {
				ans += dfs(t+1, v, u);
			} else {
				ans += dfs(0, v, u);
			}
		}
	}

	assert(leaf == 0 || ans == 0);
	return leaf + ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		cin >> has[i];
	}

	for(int i = 1; i <= n-1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout << dfs(has[1]) << "\n";
	return 0;
}

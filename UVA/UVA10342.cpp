#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;
const int oo = 1e9;
int n, t, m, q, u, v, w;
int W[maxn][maxn];
int G[maxn][maxn];

void rst() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i != j) {
				W[i][j] = G[i][j] = oo;
			}
		}
	}
}

void fw() {
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(G[i][k] != oo && G[k][j] != oo && 
						G[i][k] + G[k][j] < G[i][j] ) {
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}

}

int solve(int u, int v) {
	int ans = oo;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int val = G[u][i] + W[i][j] + G[j][v];
			if(G[u][i] != oo && W[i][j] != oo && G[j][v] != oo && val != G[u][v]) {
				ans = min(ans, val);
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m) {
		rst();
		cout << "Set #" << ++t << "\n";
		for(int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			W[u][v] = G[u][v] = w;
			W[v][u] = G[v][u] = w;
		}
		fw();
		
		cin >> q;
		for(int i = 0; i < q; i++) {
			cin >> u >> v;
			int ans = solve(u,v);
			if(ans == oo) {
				cout << "?";
			} else {
				cout << ans;
			}
			cout << "\n"; 
		}
	}
	return 0;
}

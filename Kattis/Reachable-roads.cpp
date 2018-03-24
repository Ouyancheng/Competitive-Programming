#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;
int par[maxn], e, n, t, a, b;

int p(int u) {
	return par[u] == u ? u : par[u] = p(par[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		int ans = n - 1;
		iota(par, par + maxn, 0);
		cin >> e;
		for(int i = 0; i < e; i++) {
			cin >> a >> b;
			int pa = p(a), pb = p(b);
			if(pa != pb) {
				par[pa] = pb;
				ans--;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
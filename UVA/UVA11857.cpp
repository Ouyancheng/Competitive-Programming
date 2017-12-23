#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
	int u, v;
	ll w;
};

const int maxn = 1e7;

int n, m, c, par[maxn];
int a, b;
vector<edge> E;

int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

void addEdge(int u, int v, ll w) {
	E.push_back({u, v, w});
}

bool cmp(const edge &e1, const edge &e2) {
	return e1.w < e2.w;
}

ll mst() {
	if(m == 0) return -1;
	sort(E.begin(), E.end(), cmp);

	int conn = 0; ll ans = 0;

	for(int i = 0; i < n; i++) {
		par[i] = i;
	}

	for(edge e : E) {
		int u = e.u, v = e.v; ll w = e.w;
		int pu = find(u), pv = find(v);
		if(pu != pv) {
			par[pu] = pv;
			conn++;
			ans = max(ans, w);
		}
		if(conn == n-1) {
			break;
		}
	}
	if(conn != n-1) {
		return -1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m) {
		if(n == 0 && m == 0) {
			break;
		}
		E.clear();
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			addEdge(a, b, c);
		}
		ll val = mst();
		if(val == -1) {
			cout << "IMPOSSIBLE";
		} else {
			cout << val;
		}
		cout << "\n";
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
	int u, v;
	ll w;
};

const int maxn = 450;

unordered_map<string,int> M;
int n, m, c, r, par[maxn];
string s1, s2;
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
	sort(E.begin(), E.end(), cmp);

	int conn = 0; ll cost = 0;

	for(int i = 0; i < n; i++) {
		par[i] = i;
	}

	for(edge e : E) {
		int u = e.u, v = e.v; ll w = e.w;
		int pu = find(u), pv = find(v);
		if(pu != pv) {
			par[pu] = pv;
			conn++;
			cost += w;
		}
		if(conn == n-1) {
			break;
		}
	}
	if(conn != n-1) {
		return -1;
	} else {
		return cost;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m) {
		if(n == 0 && m == 0) {
			break;
		}
		r = 0;
		E.clear();
		M.clear();
		for(int i = 0; i < n; i++) {
			cin >> s1;
			if(M.find(s1) == M.end()) {
				M[s1] = r++;
			}
		}
		for(int i = 0; i < m; i++) {
			cin >> s1 >> s2 >> c;
			addEdge(M[s1], M[s2], c);
		}
		cin >> s1;
		ll val = mst();
		if(val == -1) {
			cout << "Impossible" << "\n";
		} else {
			cout << val << "\n";
		}
	}
	return 0;
}

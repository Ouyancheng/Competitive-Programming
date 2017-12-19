#include<bits/stdc++.h>

using namespace std;

struct edge {
	int u, v, w;
};

const int maxn = 2005;

unordered_map<string,int> M;
int n, m, c, t, r, par[maxn];
string s1, s2;
vector<edge> E;

int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

void addEdge(int u, int v, int w) {
	E.push_back({u, v, w});
}

bool cmp(const edge &e1, const edge &e2) {
	return e1.w < e2.w;
}

int mst() {
	sort(E.begin(), E.end(), cmp);

	int cost = 0;

	for(int i = 0; i < n; i++) {
		par[i] = i;
	}

	for(edge e : E) {
		int u = e.u, v = e.v, w = e.w;
		int pu = find(u), pv = find(v);
		if(pu != pv) {
			par[pu] = pv;
			cost += w;
		}
	}
	return cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n >> m;
		M.clear();
		E.clear();
		r = 0;
		for(int j = 0; j < m; j++) {
			cin >> s1 >> s2 >> c;
			if(M.find(s1) == M.end()) {
				M[s1] = r++;
			}
			if(M.find(s2) == M.end()) {
				M[s2] = r++;
			}
			addEdge(M[s1], M[s2], c);
		}
		cout << mst() << "\n";
		if(i + 1 < t) {
			cout << "\n";
		}
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
	int u, v;
	ll w;
};

const int maxn = 26;

int n, m, c, t, par[maxn];
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

void mst() {
	sort(E.begin(), E.end(), cmp);

	ll cost = 0; int conn = 0;

	for(int i = 0; i < n; i++) {
		par[i] = i;
	}

	for(edge e : E) {
		int u = e.u, v = e.v; ll w = e.w;
		int pu = find(u), pv = find(v);
		if(pu != pv) {
			par[pu] = pv;
			conn++;
			if(u > v) swap(u,v);
			cout << ((char) (u + 'A')) << "-" << ((char) (v + 'A')) << " " << w << "\n";
		}
		if(conn == n-1) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n >> ws;
		E.clear();
		for(int j = 0, k = 0; j < n; j++, k = 0) {
			getline(cin, s1);
			stringstream ss(s1);
			while(getline(ss, s2, ',')) {
				ll w = stoll(s2);
				if(w) {
					addEdge(j, k, w);
				}
				k++;
			}
		}
		cout << "Case " << i + 1 << ":\n";
		mst();
	}
	return 0;
}

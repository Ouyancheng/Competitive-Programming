#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;
const int oo = 1e9 + 5;

int n, m, q, s, u, v, w, e, t;
vector<pair<int, int>> a[maxn];
priority_queue<pair<int, int>> pq;
int dis[maxn];

void d() {
	pq.push({0, s});
	fill(dis, dis + n, oo);
	dis[s] = 0;
	while((int) pq.size() > 0) {
		auto p = pq.top();
		pq.pop();
		if(abs(p.first) == dis[p.second]) {
			for(auto v : a[p.second]) {
				if(dis[p.second] + v.second < dis[v.first]) {
					dis[v.first] = dis[p.second] + abs(v.second);
					pq.push({-dis[v.first], v.first});
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m >> q >> s, n || m || q || s) {
		if(t++) {
			cout << "\n";
		}
		fill(a, a + n, vector<pair<int, int>>());
		for(int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			a[u].push_back({v, w});
		}
		d();
		for(int i = 0; i < q; i++) {
			cin >> e;
			cout << (dis[e] == oo ? "Impossible" : to_string(dis[e])) << "\n";
		}
	}
}

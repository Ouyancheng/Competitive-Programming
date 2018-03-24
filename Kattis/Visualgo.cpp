#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;
const int oo = (1LL << 31) - 1;

priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
int n, m, u, v, s, e, w, D[maxn];
vector< pair<int, int> > G[maxn];
map<int, int> C[maxn];

int d() {
	pq.push({0, s});
	fill(D, D + n, oo);
	D[s] = 0;
	C[s][0] = 1;
	
	while((int) pq.size() > 0) {
		auto p = pq.top();
		pq.pop();
		int uw = p.first, u = p.second;
		if(u == e) {
			break;
		} else if(uw > D[u]) {
			continue;
		}
		
		for(auto vi : G[u]) {
			int w = vi.first, v = vi.second;
			if(D[u] + w <= D[v]) {
				C[v][D[u] + w] += C[u][D[u]];
				if(D[u] + w < D[v]) {
					pq.push({D[u] + w, v});
				}
				D[v] = D[u] + w;
			}
		}
	}
	return C[e][D[e]];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		G[u].push_back({w, v});
	}
	cin >> s >> e;
	cout << d() << endl;
	return 0;
}
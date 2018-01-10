#include<bits/stdc++.h>

using namespace std;

const int maxn = 32;
const int oo = 1 << 30;

int n, t, r, a, b;
vector<int> G[maxn];
unordered_map<int,int> M;

void addEdge(int u, int v) {
	if(M.find(u) == M.end()) {
		M[u] = r++;
	}
	if(M.find(v) == M.end()) {
		M[v] = r++;
	}
	G[M[u]].push_back(M[v]);
	G[M[v]].push_back(M[u]);
}

void rst() {
	for(int i = 0; i < r; i++) {
		G[i].clear();
	}
	r = 0;
	M.clear();
}

int work(int s, int d) {
	queue<int> q;
	q.push(s);

	int dis[r], ans = r;
	fill(dis, dis + r, oo);
	dis[s] = 0;

	while((int) q.size() > 0) {
		int u = q.front();
		q.pop();

		if(dis[u] > d) {
			break;
		}

		ans--;

		for(int v : G[u]) {
			if(dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n) {
		if(!n) {
			break;
		}
		rst();
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			addEdge(a, b);
		}
		while(cin >> a >> b) {
			if(a == 0 && b == 0) {
				break;
			}
			cout << "Case " << ++t << ": " << work(M[a], b) << " nodes not reachable from node " << a << " with TTL = " << b << ".\n";
		}
	}
	return 0;
}
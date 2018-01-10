#include<bits/stdc++.h>

using namespace std;

const int oo = 1 << 30;

int n, test, x, y, z, s, t, c;

struct edge {
	int u, v, c;
};

struct edmondkarp {
	int v, e;
	vector<edge> G;
	vector<int> next, head, par;

	edmondkarp(int n1, int n2) {
		v = n1, e = n2;
		head.assign(v + 1, -1);
		next.assign(4 * e + 1, -1);
	}

	void addEdge(int u, int v, int c) {
		int pre = 0;

		G.push_back({u, v, c});
		pre = head[u];
		head[u] = (int) G.size() - 1;
		next[head[u]] = pre;

		G.push_back({v, u, 0});
		pre = head[v];
		head[v] = (int) G.size() - 1;
		next[head[v]] = pre;
	}

	bool hasAugmentingPath(int s, int t) {
		queue<int> q;
		q.push(s);
		
		int dis[v];
		fill(dis, dis + v + 1, oo);
		par.assign(v + 1, -1);
		dis[s] = 0;

		while((int) q.size() > 0) {
			int e = q.front();
			q.pop();
			for(int i = head[e]; i >= 0; i = next[i]) {
				int eu = G[i].u, ev = G[i].v, ec = G[i].c;
				if(dis[eu] + 1 < dis[ev] && ec) {
					dis[ev] = dis[eu] + 1;
					par[ev] = i;
					if(ev == t) {
						goto finish;
					}
					q.push(ev);
				}
			}
		}
		finish:
		return dis[t] != oo;
	}

	int maxFlow(int s, int t) {
		int ans = 0, cap = 0;

		while(hasAugmentingPath(s, t)) {
			cap = oo; int p = t;
			while(p != s) {
				edge cur = G[par[p]];
				cap = min(cap, cur.c);
				p = cur.u;
			}

			ans += cap;
			p = t;

			while(p != s) {
				G[par[p]].c -= cap;
				G[par[p] ^ 1].c += cap;
				p = G[par[p]].u;
			}
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n) {
		if(!n) {
			break;
		}
		cin >> s >> t >> c;
		edmondkarp ek(n, c);
		for(int i = 0; i < c; i++) {
			cin >> x >> y >> z;
			ek.addEdge(x, y, z);
			ek.addEdge(y, x, z);
		}
		cout << "Network " << ++test << "\n";
		cout << "The bandwidth is " << ek.maxFlow(s, t) << ".\n";
		if(!cin.eof()) {
			cout << "\n";
		}
	}
	return 0;
}
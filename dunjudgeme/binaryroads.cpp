#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
const int oo = 1e8;

vector< pair<int,int> > G[maxn];
int a, b, c, n, m, dist[maxn][2];

struct node {
	int a, b, c;
};

void addEdge(int u, int v, int w) {
	G[u].push_back(make_pair(v, w));
	G[v].push_back(make_pair(u, w));
}

int work(int t = 0) {
	if(t > 1) {
		return oo;
	}
	queue<node> d;
	d.push({0, 0, t});
	
	for(int i = 1; i < n; i++) {
		dist[i][0] = dist[i][1] = oo;
	}

	while((int) d.size() > 0) {
		node p = d.front();
		d.pop();
		int u = p.a, tt = p.c;
		for(int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i].first, w = G[u][i].second;
			if(tt == w) {
				if(dist[v][1-tt] > dist[u][tt] + 1) {
					dist[v][1-tt] = dist[u][tt] + 1;
					if(dist[n-1][t] != oo && dist[n-1][1-t] != oo) {
						goto ret;
					}
					d.push({v, dist[v][1-tt], 1 - tt});
				}
			}
		}
	}
	ret:
	int ans = min(dist[n-1][t], dist[n-1][1-t]);
	return min(ans, work(t+1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		addEdge(a, b, c);
	}
	int ans = work();
	if(work() == oo) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
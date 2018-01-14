#include<bits/stdc++.h>

using namespace std;

const int oo = 1 << 30;

int a, sum;
char c;
string s, s2, s3;

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
		next.assign(2 * e + 1, -1);
	}

	void clear() {
		head.assign(v + 1, -1);
		next.assign(2 * e + 1, -1);
		G.clear();
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

	string getAssignment() {
		char config[11];
		memset(config, 0, sizeof config);
		fill(config, config + 10, '_');
		for(int i = 0; i < 26; i++) {
			for(int j = head[i]; j >= 0; j = next[j]) {
				int eu = G[j].u, ev = G[j].v, ec = G[j].c;
				if(ec == 0) {
					config[ev-26] = eu + 'A';
				}
			}
		}
		return string(config);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	edmondkarp ek(60, 310);

	while(getline(cin, s)) {
		if((int) s.length() > 0 && s.back() == '\r') {
			s.pop_back();
		}
		if((int) s.length() == 0) {
			for(int i = 0; i < 10; i++) {
				ek.addEdge(26 + i, 26 + 10 + 1, 1);
			}
			if(ek.maxFlow(26 + 10, 26 + 10 + 1) == sum) {
				cout << ek.getAssignment();
			} else {
				cout << "!";
			}
			cout << "\n";
			ek.clear();
			sum = 0;
			continue;
		}
		stringstream ss(s);
		getline(ss, s2, ' ');
		getline(ss, s3, ';');
		
		sum += s2[1] - '0';

		for(int i = 0; i < (int) s3.length(); i++) {
			ek.addEdge(s2[0] - 'A', 26 + s3[i] - '0', 1);
		}
		ek.addEdge(26 + 10, s2[0] - 'A', s2[1] - '0');
	}
	if(sum) {
		for(int i = 0; i < 10; i++) {
			ek.addEdge(26 + i, 26 + 10 + 1, 1);
		}
		if(ek.maxFlow(26 + 10, 26 + 10 + 1) == sum) {
			cout << ek.getAssignment();
		} else {
			cout << "!";
		}
	}
	cout << "\n";
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;

bool vis[maxn], inp[maxn];
vector<int> path;
int G[maxn], out[maxn], t, n, mgs;
vector<int> grp[maxn], gs[maxn];

void dfs(int u) {
	inp[u] = vis[u] = 1;
	path.push_back(u);

	int v = G[u];

	if(inp[v]) {
		int cur = (int) path.size() - 1;
		while(1) {
			grp[t].push_back(path[cur]);
			if(path[cur--] == v) {
				break;
			}
		}
		reverse(grp[t].begin(), grp[t].end());
		gs[(int) grp[t].size()].push_back(t);
		mgs = max(mgs, (int) grp[t].size());
		t++;
	} else if(!vis[v]) {
		dfs(v);
	}

	inp[u] = 0;
	path.pop_back();
}

void oproc(int g) {
	for(int i = 0, sz = (int) grp[g].size(); i < sz; i++) {
		out[grp[g][i]] = grp[g][(i+sz/2+1) % sz];
	}
}

void eproc(int g1, int g2) {
	for(int i = 0, sz = (int) grp[g1].size(); i < sz; i++) {
		out[grp[g1][i]] = grp[g2][i % sz];
		out[grp[g2][i]] = grp[g1][(i+1) % sz];
	}
}

void work() {
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			dfs(i);
		}
	}

	for(int i = 1; i <= mgs; i++) {
		if(i & 1) {
			for(int j = 0; j < (int) gs[i].size(); j++) {
				oproc(gs[i][j]);
			}
		} else {
			for(int j = 0; j < (int) gs[i].size(); j += 2) {
				eproc(gs[i][j], gs[i][j+1]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> G[i];
	}

	work();

	for(int i = 0; i < n; i++) {
		cout << out[i] << " ";
	}
	cout << "\n";

	return 0;
}

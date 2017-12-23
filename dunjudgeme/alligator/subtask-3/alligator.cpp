#include<bits/stdc++.h>

using namespace std;

const int mul = 4e6 + 5;

char g[mul];
int n, m, c[mul], lz[mul], dn[mul], ds[mul], dw[mul], de[mul];

void sweep(queue<int> &q) {
	for(int i = 0; i < n; i++) {
		for(int k = 0, from = 0, to = -1; k < m; k++) { // sweep to the east
			int ci = i * m + k;
			if(g[ci] == 'W') {
				c[ci] += from;
			}
			dw[ci] = to;
			if(g[ci] == 'E') {
				to = k;
			}
			if(g[ci] != '.') {
				from++;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int k = m-1, from = 0, to = -1; k >= 0; k--) { // sweep to the west
			int ci = i * m + k;
			if(g[ci] == 'E') {
				c[ci] += from;
			}
			de[ci] = to;
			if(g[ci] == 'W') {
				to = k;
			}
			if(g[ci] != '.') {
				from++;
			}
		}
	}

	for(int j = 0; j < m; j++) {
		for(int k = n-1, from = 0, to = -1; k >= 0; k--) { // sweep to the north
			int ci = k * m + j;
			if(g[ci] == 'S') {
				c[ci] += from;
			}
			ds[ci] = to;
			if(g[ci] == 'N') {
				to = k;
			}
			if(g[ci] != '.') {
				from++;
			}
		}
	}

	for(int j = 0; j < m; j++) {
		for(int k = 0, from = 0, to = -1; k < n; k++) { // sweep to the south
			int ci = k * m + j;
			if(g[ci] == 'N') {
				c[ci] += from;
			}
			if(c[ci] == 0 && g[ci] != '.') {
				q.push(ci);
			}
			dn[ci] = to;
			if(g[ci] == 'S') {
				to = k;
			}
			if(g[ci] != '.') {
				from++;
			}
		}
	}
}

void work(int t, int fromi, int toi, queue<int> &q) {
	if(t >= 0) {
		if(g[fromi] == g[toi]) {
			c[toi] -= (lz[fromi] + 1);
			lz[toi] += lz[fromi] + 1;
			if(c[toi] == 0) {
				q.push(toi);
			}
		} else {
			c[toi]--;
			lz[toi]++;
			if(c[toi] == 0) {
				q.push(toi);
			}
		}
	}
}

void relax(int i, int j, queue<int> &q, int d = 0) {
	if(d == 4) return;
	int t = -1, fromi = i * m + j, toi = -1;
	if(d == 0) {
		toi = i * m + (t = de[fromi]);
	} else if(d == 1) {
		toi = i * m + (t = dw[fromi]);
	} else if(d == 2) {
		toi = (t = dn[fromi]) * m + j;
	} else if(d == 3) {
		toi = (t = ds[fromi]) * m + j;
	}
	work(t, fromi, toi, q);
	relax(i, j, q, d+1);
}

int solve() {
	int ans = 0;
	queue<int> q;
	sweep(q);

	while((int) q.size() > 0) {
		int p = q.front();
		q.pop();
		ans++;
		relax(p/m, p%m, q);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> g[i*m+j];
		}
	}
	cout << solve() << "\n";
}

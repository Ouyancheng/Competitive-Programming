#include<bits/stdc++.h>

using namespace std;

struct edge {
	int a, b, i;
	bool d;
};

const int maxn = 2e3+5;
const int maxe = 5e5 + 5;

int n, m, a, b, rc, bc, dummy;
bool c;
vector<edge> edges;
int par[maxn], use[maxe];

int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

bool cmp(edge &u, edge &v) {
	if(u.d == 1 && v.d == 0) {
		return 1;
	} else if(u.d == 0 && v.d == 1) {
		return 0;
	}
	return u.i < v.i;
}

int mst1() {
	int cnt = 0;
	sort(edges.begin(), edges.end(), cmp);
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	for(edge e : edges) {
		if(cnt > n/2) {
			break;
		}
		int u = e.a, v = e.b, pu = find(u), pv = find(v);
		if(pu == pv) {
			continue;
		}
		par[pu] = pv;
		if(e.d == 0) {
			cnt++;
			use[e.i] = 1;
		}
	}
	return cnt;
}

int mst2(int init) { // mst must be called first
	int cnt = init;
	reverse(edges.begin(), edges.end());

	for(int i = 0; i < n; i++) {
		par[i] = i;
	}

	for(edge e : edges) {
		int u = e.a, v = e.b, pu = find(u), pv = find(v);
		if(use[e.i]) {
			par[pu] = pv;
		}
	}

	for(edge e : edges) {
		int u = e.a, v = e.b, pu = find(u), pv = find(v);
		if(cnt == (n-1)/2 && e.d == 0) {
			continue;
		}
		if(pu == pv) {
			continue;
		}
		par[pu] = pv;
		use[e.i] = 1;
		if(e.d == 0) {
			cnt++;
		} else {
			dummy++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if(c) {
			bc++;
		} else {
			rc++;
		}
		edges.push_back({a, b, i, c});
	}

	if(n % 2 == 0 || rc < (n-1)/2 || bc < (n-1)/2) {
		cout << "NO" << "\n";
		return 0;
	}

	int must = mst1();
	
	if(must > (n-1)/2) {
		cout << "NO" << "\n";
		return 0;
	}

	int all = mst2(must);
	
	if(all != (n-1)/2) {
		cout << "NO" << "\n";
		return 0;
	} else {
		assert(dummy == (n-1)/2);
		cout << "YES" << "\n";
		for(int i = 0; i < m; i++) {
			if(use[i]) {
				cout << i << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
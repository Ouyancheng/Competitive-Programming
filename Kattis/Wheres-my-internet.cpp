#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, a, b, par[maxn];

int f(int x) {
	return par[x] == x ? x : par[x] = f(par[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	iota(par, par + n + 1, 0);
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		int pa = f(a), pb = f(b);
		par[pa] = pb;
	}
	bool ok = 1;
	par[f(1)] = 1;
	par[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(f(i) != 1) {
			cout << i << "\n";
			ok = 0;
		}
	}
	if(ok) {
		cout << "Connected\n";
	}
	return 0;
}

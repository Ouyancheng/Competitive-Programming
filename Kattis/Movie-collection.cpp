#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 2;

int n, q, t, a, top, ans, f[maxn * 2], ind[maxn];

void upd(int i, int v) {
	while(i <= n+q) {
		f[i] += v;
		i += (i & -i);
	}
}

int qr(int i) {
	int ans = 0;
	while(i > 0) {
		ans += f[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> q;
		top = n, ans = 0;
		fill(f, f + n + q + 1, 0);

		for(int i = 1; i <= n; i++) {
			upd(i, 1);
			ind[i] = n - i + 1;
		}
		for(int i = 0; i < q; i++) {
			cin >> a;
			cout << qr(top) - qr(ind[a]);
			upd(ind[a], -1);
			if(i != q - 1) {
				cout << " ";
			}
			ind[a] = ++top;
			upd(ind[a], 1);
		}
		cout << "\n";
	}
	return 0;
}

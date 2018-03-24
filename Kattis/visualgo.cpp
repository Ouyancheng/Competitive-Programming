#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n, f[maxn], a;

int qr(int i) {
	int ans = 0;
	while(i) {
		ans += f[i];
		i -= (i & -i);;
	}
	return ans;
}

void upd(int i, int v) {
	while(i < maxn) {
		f[i] += v;
		i += (i & -i);
	}
}

int select(int x) {
	int cur = 0; x--;
	int hi = (int) log2(maxn - 1);
	for(int k = hi; k >= 0; k--) {
		int p = cur + (1 << k);
		if(p < maxn && f[p] <= x) {
			x -= f[p];
			cur += (1 << k);
		}
	}
	return cur + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(1);
	cout << fixed;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		upd(++a, 1);
		if(i&1) {
			cout << 1.0 * (select(i/2 + 1) - 1) << "\n";
		} else {
			cout << (select(i/2) - 1 + select(i/2 + 1) - 1) / 2.0 << "\n";
		}
	}
	return 0;
}
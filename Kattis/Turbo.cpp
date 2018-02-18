#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n, a, ind[maxn], f[2 * maxn], lo, hi;

void upd(int i, int v) {
	while(i <= 2*n) {
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
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		upd(a+n, 1);
		ind[a] = n+i;
	}

	for(int i = 1, lo = 1, hi = n; i <= n; i++) {
		if(i&1) {
 			cout << qr(ind[lo] - 1) - qr(n) << "\n";
			upd(ind[lo], -1);
			ind[lo] = lo;
			upd(ind[lo], 1);
			lo++;
		} else {
			cout << qr(2*n) - qr(ind[hi]) << "\n";
			upd(ind[hi], -1);
			ind[hi] = hi;
			upd(ind[hi], 1);
			hi--;
		}
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int t, n, a[maxn];
unordered_map<int, bool> M;

int solve() {
	int lo = 0, hi = 0, ans = 0;
	M.clear();

	while(hi < n) {
		while(hi < n && M[a[hi]] == 0) {
			M[a[hi]] = 1;
			hi++;
		}
		hi--;
		ans = max(ans, hi - lo + 1);
		if(hi == n-1) {
			break;
		}
		hi++;
		while(M[a[hi]]) {
			M[a[lo]] = 0;
			lo++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	M.reserve(1 << 20);

	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << solve() << "\n";
	}
	return 0;
}

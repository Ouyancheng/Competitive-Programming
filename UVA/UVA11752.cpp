#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
int t, a[maxn], n;
unordered_map<int, int> M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	M.reserve(1 << 20);
	cin >> t;
	while(t--) {
		int hi = 0, lo = 0, ans = 0;
		cin >> n;
		M.clear();
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		while(1) {
			while(hi < n && M[a[hi]] == 0) {
				M[a[hi]]++;
				hi++;
			}
			hi--;
			ans = max(ans, hi - lo + 1);
			if(hi == n-1) {
				break;
			}
			hi++;
			while(M[a[hi]] != 0) {
				M[a[lo]]--;
				lo++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

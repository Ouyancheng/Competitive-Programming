#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], t, n, lo = 1, hi = 1, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	while(1) {
		while(hi <= n && a[hi] - a[lo-1] <= t) {
			ans = max(ans, hi - lo + 1);
			hi++;
		}
		if(hi > n) {
			break;
		}
		hi--;
		lo++;
	}
	cout << ans << "\n";
}

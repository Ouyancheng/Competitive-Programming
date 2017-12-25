#include<bits/stdc++.h>

using namespace std;

int a[1005], n, k, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	for(int i = 1; i <= n-k+1; i++) {
		ans = max(ans, a[i+k-1] - a[i-1]);
	}
	cout << ans << "\n";
	return 0;
}

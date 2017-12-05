#include<iostream>

using namespace std;

const int maxn = 1e5+5;
int n, k, a[maxn], ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = k+1; i <= n; i++) {
		if(a[i] != a[i-1]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	for(int i = 1; i <= k-1; i++) {
		if(a[i] != a[n]) {
			ans = max(ans,i);
		}
	}
	cout << ans << "\n";
	return 0;
}
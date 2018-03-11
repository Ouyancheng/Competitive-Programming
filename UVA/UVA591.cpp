#include<bits/stdc++.h>

using namespace std;

const int maxn = 55;
int n, a[maxn], t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n, n) {
		cout << "Set #" << ++t << "\n";
		int sum = 0, ans = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		for(int i = 0; i < n; i++) {
			ans += abs(sum / n - a[i]);
		}
		cout << "The minimum number of moves is " << ans / 2 << ".\n\n";
	}
	return 0;
}
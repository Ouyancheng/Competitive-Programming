#include<bits/stdc++.h>

using namespace std;

long long coins[1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cc, n;
	cin >> cc;
	for(int i = 0; i  < cc; i++) {
		cin >> n;
		int ans = 1;
		for(int i = 1; i  <= n; i++) {
			cin >> coins[i-1];
		}
		long long total = coins[0];
		for(int i = 1; i < n; i++) {
			if(total >= coins[i]) {
				total -= coins[i-1];
			} else {
				ans++;
			}
			total += coins[i];
		}
		cout << ans << "\n";
	}
	return 0;
}

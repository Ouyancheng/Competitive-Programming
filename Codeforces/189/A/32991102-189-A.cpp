#include<iostream>

using namespace std;

int n, dp[4005], x;

int main() {
	cin >> n;
	for(int j = 0; j < 3; j++) {
		cin >> x;
		for(int i = x; i <= n; i++) {
			if(i - x == 0) {
				dp[i] = max(dp[i],1);
			} else {
				dp[i] = max(dp[i],dp[i-x] ? 1 + dp[i-x] : 0);
			}
		}
	}
	cout << dp[n] << "\n";
	return 0;
}
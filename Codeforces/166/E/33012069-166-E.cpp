#include<iostream>

using namespace std;

int n, dp[4][(int)1e7+5];
const int mod = 1e9 + 7;

int main() {
	cin >> n;
	dp[3][0] = 1;
	for(int j = 1; j <= n; j++) {
		for(int i = 0; i < 4; i++) {
			dp[i][j] = (0LL + dp[(i+4-1)%4][j-1] + dp[(i+4-2)%4][j-1] + dp[(i+4-3)%4][j-1]) % mod;
		}
	}
	cout << dp[3][n] << "\n";
}

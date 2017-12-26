#include<bits/stdc++.h>

using namespace std;

int n, dp[2][5000];
char s[5001];

int f() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(s[i] == s[n-1-j]) {
				dp[i%2][j] = 1;
				if(i && j) {
					dp[i%2][j] += dp[(i-1)%2][j-1];
				}
			} else {
				if(i) {
					dp[i%2][j] = dp[(i-1)%2][j];
				}
				if(j) {
					dp[i%2][j] = max(dp[i%2][j], dp[i%2][j-1]);
				}
			}
		}
	}
	return dp[(n-1)%2][n-1];
}

int main() {
    scanf("%d %s", &n, s);
	cout << n - f() << "\n";
	return 0;
}

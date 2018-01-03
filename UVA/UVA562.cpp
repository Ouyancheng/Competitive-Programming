#include<bits/stdc++.h>

using namespace std;

int n, b[105], m, sum;
bool dp[2][50005];

void ss() {
	for(int i = 0; i <= sum; i++) {
		dp[0][i] = 0;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j <= sum; j++) {
			if(j >= b[i]) {
				dp[i%2][j] = dp[(i-1)%2][j] || dp[(i-1)%2][j-b[i]];
			} else {
				dp[i%2][j] = dp[(i-1)%2][j];
			}
		}
	}
}

int f() {
	int ans = (int) 1e9;
	for(int i = 0; i <= sum; i++) {
		if(dp[m%2][i]) {
			ans = min(ans, abs(i-(sum-i)));
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	while(n--) {
		cin >> m;
		sum = 0;
		for(int i = 1; i <= m; i++) {
			cin >> b[i];
			sum += b[i];
		}
		ss();
		cout << f() << "\n";
	}

	return 0;
}

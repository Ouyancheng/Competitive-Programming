#include<iostream>

using namespace std;

const int maxn = 105;
int n, a[maxn], t, sum;
int dp[maxn][maxn];

bool f(int tot, int i=n) {
	if(dp[tot][i] != -1) {
		return dp[tot][i];
	} else if(i < 0) {
		return 0;
	} else {
		if(tot - a[i-1] < 0) {
			return dp[tot][i] = f(tot,i-1);
		}
		return dp[tot][i] = f(tot-a[i-1],i-1) || f(tot,i-1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		a[i] = t < 200 ? 1 : 2;
		sum += a[i];
	}
	if(sum % 2 != 0) {
		cout << "NO" << "\n";
		return 0;
	}
	for(int i = 0; i <= sum/2; i++) {
		for(int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	for(int j = 0; j <= n; j++) {
		dp[0][j] = 1;
	}
	f(sum/2);
	if(dp[sum/2][n]) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	cout << "\n";
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n,p,q,r,a;
long long dp[100005][3];

int main() {
	//freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> p >> q >> r;

	dp[0][0] = dp[0][1] = dp[0][2] = LLONG_MIN;

	for(int i = 1; i <= n; i++) {
		cin >> a;
		dp[i][0] = max(dp[i-1][0],1LL*a*p);
		dp[i][1] = max(dp[i-1][1],dp[i][0]+1LL*a*q);
		dp[i][2] = max(dp[i-1][2],dp[i][1]+1LL*a*r);
	}
	cout << dp[n][2] << "\n";
	return 0;
}
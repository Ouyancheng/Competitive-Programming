#include<iostream>

using namespace std;

#define MAX_N 10001
#define MAX_P 10
#define MOD 1000000007

int dp[MAX_N][MAX_P];
int n,p,t;

int f(int cur,int r) {
	if(dp[cur][r] != -1) return dp[cur][r];
	if(cur == n) return 1;
	dp[cur][r] = 0;
	if(r < p-1) {
		return dp[cur][r] = (0LL+f(cur+1,r+1)+f(cur+1,0))%MOD;
	}
	return dp[cur][r] = f(cur+1,0)%MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> p;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < p; j++) {
				dp[i][j] = -1;
			}
		}
		cout << f(1,0)%MOD << "\n";
	}
}
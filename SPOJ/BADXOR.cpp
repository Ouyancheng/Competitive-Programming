#include<iostream>
#include<sstream>
 
using namespace std;
 
#define MOD 100000007
 
int n,m,cc,a;
int dp[1300][1301];
int arr[1300];
int powofa[1300];
long long ans;
 
void powMod(int a, int b, int mod) {
	powofa[0] = 1;
	int lo = 1;
    while(lo <= b) {
    	powofa[lo] = powofa[lo-1] * a % mod;
    	lo++;
    }
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	powMod(2,1300,MOD);
	cin >> cc;
	for(int cn = 1; cn <= cc; cn++) {
		cin >> n >> m;
		ans = 0;
		for(int i = 0; i < 1300; i++)
			for(int j = 0; j < 1301; j++)
				dp[i][j] = 0;
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < 1301; j++) {
				dp[i][j] = (dp[i][j] + (dp[i-1][j] + dp[i-1][j^arr[i]]) % MOD) % MOD;
			}
		}
		for(int i = 1; i <= m; i++) {
			cin >> a;
			ans = (ans + dp[n][a]) % MOD;
		}
		cout << "Case " << cn << ": " << (powofa[n]+MOD-ans)%MOD << "\n";
	}
	return 0;
} 
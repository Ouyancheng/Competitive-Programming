#include <iostream>
#include <cmath>

using namespace std;

#define INF 1<<30

int fiv,ten,tw,fif,od,td;

int dp[1000005][7];
int dp2[1000005][7];
int coin[] = { 0, 5, 10, 20, 50, 100, 200 };
int qn[7];
double t;
int owe;
int ans;

void f(int dp[1000005][7],int tval) {
	for(int i = 1; i <= 6; i++) if(qn[i]) dp[coin[i]][i] = 1;

	for(int i = 1; i <= tval; i++)
		for(int j = 0; j <= 6; j++)
			dp[i][j] = INF;

	for(int i = 5; i <= tval; i+=5) {
		for(int j = 1; j <= 6; j++) {
			for(int k = 0; k <= qn[j] && k*coin[j] <= i; k++) {
				dp[i][j] = min(dp[i][j],k+dp[i-k*coin[j]][j-1]);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	qn[1] = INF, qn[2] = INF, qn[3] = INF, qn[4] = INF, qn[5] = INF, qn[6] = INF;
	f(dp2,500);
	while(cin >> fiv >> ten >> tw >> fif >> od >> td) {
		if((fiv==0&&ten==0&&tw==0&&fif==0&&od==0&&td==0)) break;
		cout.width(3);
		cout << right;
		ans = INF;
		cin >> t;
		owe = int(t*1000)/10;
		qn[1] = fiv, qn[2] = ten, qn[3] = tw, qn[4] = fif, qn[5] = od, qn[6] = td;
		f(dp,700);
		for(int i = 700; i > owe; i-=5) {
			if(dp[i][6] != INF) ans = min(ans,dp[i][6] + dp2[i-owe][6]);
		}
		if(dp[owe][6]!=INF) ans = min(ans,dp[owe][6]);
		cout << ans << endl;
	}
	return 0;
}
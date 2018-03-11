#include<bits/stdc++.h>

using namespace std;

const int maxn = 50;

int kd[maxn], kw[maxn], kv[maxn], d, v, t, w, n;
int dp[2][1005];
bool mv[maxn][1005];

int f() {
	for(int j = 1; j <= t; j++) dp[0][j] = dp[1][j] = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= t; j++) {
			mv[i][j] = 0;
			dp[i%2][j] = dp[(i+1)%2][j];
			if(kw[i] <= j) {
				if(dp[(i+1)%2][j] < kv[i] + dp[(i+1)%2][j-kw[i]]) {
					mv[i][j]  = 1;
				}
				dp[i%2][j] = max(kv[i] + dp[(i+1)%2][j-kw[i]], dp[(i+1)%2][j]);
			}
		}
	}
	return dp[(n-1)%2][t];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> t >> w) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> d >> v;
			kd[i] = d;
			kw[i] = w * d + 2 * w * d;
			kv[i] = v;
		}

		cout << f() << "\n";

		int cur = n-1, lim = t;
		stack<int> opt;

		while(cur >= 0) {
			if(mv[cur][lim]) {
				opt.push(cur);
				lim -= kw[cur];
			}
			cur--;
		}

		cout << opt.size() << "\n";

		while((int) opt.size() > 0) {
			cout << kd[opt.top()] << " " << kv[opt.top()] << "\n";
			opt.pop();
		}
		if(cin >> ws, !cin.eof()) cout << "\n";
	}
	return 0;
}

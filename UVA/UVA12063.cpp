#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll dp[70][35][205];
int n, d, t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    cin >> n >> d;
    cout << "Case " << tt << ": ";
    if((n & 1) || d == 0) {
      cout << 0 << "\n";
      continue;
    }
    for(int i = 0; i <= n; i++) {
      for(int j = 1; j <= n/2; j++) {
        for(int k = 0; k < d; k++) {
          dp[i][j][k] = 0;
        }
      }
    }
    dp[1][1][1%d] = 1;
    for(int i = 2; i <= n; i++) {
      for(int j = 1; j <= n/2; j++) {
        for(int k = 0; k < d; k++) {
          dp[i][j][(k*2+1)%d] += dp[i-1][j-1][k];
          dp[i][j][(k*2)%d] += dp[i-1][j][k];
        }
      }
    }
    cout << dp[n][n/2][0] << "\n";
  }
  return 0;
}
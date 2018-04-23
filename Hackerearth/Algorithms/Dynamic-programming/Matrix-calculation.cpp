#include<bits/stdc++.h>

using namespace std;

const int maxn = 20, modulo = 1e9 + 7;
int n, m, a, dp[maxn][1 << maxn], c[maxn][maxn];
vector<int> v[maxn + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a;
            c[i][a]++;
        }
    }
    for(int i = 1, tmp = 0; i < (1 << n); i++, tmp = 0) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                tmp |= (1 << j);
            }
        }
        v[__builtin_popcount(tmp)].push_back(tmp);
    }
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            for(int j = 0; j < n; j++) {
                dp[i][1 << j] = c[i][j];
            }
        } else {
            for(auto mask : v[i + 1]) {
                for(int k = 0; k < n; k++) {
                    if(mask & (1 << k)) {
                        dp[i][mask] = (dp[i][mask] + 1LL * dp[i - 1][mask & ~(1 << k)] * c[i][k]) % modulo;
                    }
                }
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1];
}
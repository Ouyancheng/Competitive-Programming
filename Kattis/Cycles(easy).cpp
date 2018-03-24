#include<bits/stdc++.h>

using namespace std;

const int mod = 9901;
const int maxn = 10;
int t, B[maxn], a, b, k, n;

int dfs(int cur = 0, int depth = 0, int mask = (1 << n) - 2) {
    if(depth == n - 1 && (B[cur] & 1) == 0) {
        return 1;
    } else if(depth == n - 1) {
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(cur != i && (B[cur] & (1 << i)) == 0 && (mask & (1 << i))) {
            ans = (ans + dfs(i, depth + 1, mask & ~(1 << i))) % mod;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        memset(B, 0, sizeof B);
        cin >> n >> k;
        for(int j = 0; j < k; j++) {
            cin >> a >> b;
            a--, b--;
            B[a] |= (1 << b);
            B[b] |= (1 << a);
        }
        cout << "Case #" << i << ": " << (dfs() * 4951LL) % mod  << "\n";
    }
    return 0;
}
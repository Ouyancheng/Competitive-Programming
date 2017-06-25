#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>

ll dp[(int)1e5+1][2][2];
vector<int> adj[(int)1e5+1];
int n, a, b;
const int MOD = 1e9 + 7;

ll solve(int cur,int par,int curc,int parc) {
    if(dp[cur][curc][parc] >= 2) return dp[cur][curc][parc];
    dp[cur][curc][parc] = 1;
    vi nei = adj[cur];
    ll tmp = 0;
    for(int i = 0; i < nei.size(); i++) {
        if(nei[i] != par) {
            dp[cur][curc][parc] = (dp[cur][curc][parc] * (solve(nei[i],cur,0,curc)+solve(nei[i],cur,1,curc) % MOD)) % MOD;
        }
    }
    if(curc != parc) {
        tmp = 1;
        for(int i = 0; i < nei.size(); i++) {
            if(nei[i] != par) {
                tmp = (tmp * solve(nei[i],cur,parc,curc)) % MOD;
            }
        }
    }
    dp[cur][curc][parc] = (dp[cur][curc][parc] + MOD - tmp) % MOD;
    return dp[cur][curc][parc];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i <= n; i++) {
        adj[i] = vector<int>();
    }
    
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d",&a,&b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    printf("%lld\n",(solve(1,0,0,1)+solve(1,0,1,0))%MOD);
    return 0;
}

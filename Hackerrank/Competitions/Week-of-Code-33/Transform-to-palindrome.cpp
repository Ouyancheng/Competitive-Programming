#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100005
#define MAX_M 1005
#define MAX_K 1000005

int n,m,k,a,b;

int par[MAX_N];
int dp[MAX_M][MAX_M];
int s[MAX_M];

int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

int lps(int i,int j) {
    if(dp[i][j] != 0) return dp[i][j];
    if(i == j) {
        return dp[i][i] = 1;
    } else if(j - i == 1) {
        if(s[i] == s[j]) {
            return dp[i][j] = 2;
        } else {
            return dp[i][j] = 1;
        }
    } else {
        if(s[i] == s[j]) return dp[i][j] = 2+lps(i+1,j-1);
        else return dp[i][j] = max(lps(i+1,j),lps(i,j-1));
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 1; i < MAX_N; i++) par[i] = i;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        par[find(a)] = find(b);
    }
    for(int i = 0; i < m; i++) {
        cin >> s[i];
        s[i] = find(s[i]);
    }
    cout << lps(0,m-1) << "\n";
    return 0;
}

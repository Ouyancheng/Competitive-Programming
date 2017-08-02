#include <bits/stdc++.h>
using namespace std;

#define MAX_V 100005
#define ii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ll long long

int u,v,q,n,m,a,b;
int par[MAX_V];
ll ans;

int find(int u) { return par[u] == u ? u : (par[u] = find(par[u])); }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> m >> a >> b;
        ans = 0;
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--, v--;
            par[find(u)] = find(v);
        }
        for(int i = 0; i < n; i++) {
            if(find(i) == i) {
                ans += a;
            } else {
                if(a > b) ans += b;
                else ans += a;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

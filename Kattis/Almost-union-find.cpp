#include<bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n,m,a,b,c,par[MAX_N],sz[MAX_N];
long long sum[MAX_N];

int find(int x) {
    return (par[x] == x) ? x : par[x] = find(par[x]);
}

void join(int u,int v) {
    int pu = find(u), pv = find(v);
    if(pu == pv) return;
    if(sz[pu] > sz[pv]) swap(pu,pv);

    sz[pu] += sz[pv];
    sum[pu] += sum[pv];
    par[pv] = pu;
}

void move(int u,int v) {
    int pu = find(u), pv = find(v);
    if(pu == pv) return;

    sz[pu]--;
    sum[pu] -= u;
    sz[pv]++;
    sum[pv] += u;
    par[u] = pv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++) {
            par[i] = par[i+n] = i+n;
            sum[i+n] = i;
            sz[i+n] = 1;
        }
        for(int i = 0; i < m; i++) {
            cin >> a;
            if(a == 1) {
                cin >> b >> c;
                join(b,c);
            } else if(a == 2) {
                cin >> b >> c;
                move(b,c);
            } else {
                cin >> b;
                cout << sz[find(b)] << " " << sum[find(b)] << "\n";
            }
        }
    }
    return 0;
}
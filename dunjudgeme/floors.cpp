#include<iostream>
#include<vector>

using namespace std;

struct dsu {
    int n;
    vector<int> par;
    dsu(int size = 0) {
        n = size;
        par.resize(n + 1);
        for (int i = 0; i <= n; i++) par[i] = i;
    }
    int find(int x) {
        if (x != par[x])
            par[x] = find(par[x]);
        return par[x];
    }
    int query(int c) {
        int at = find(c);
        if (at == 1) par[at] = n;
        else par[at] = at - 1;
        return at;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c, q;
    cin >> n >> c;
    dsu d = dsu(n);
    while (c--) {
        cin >> q;
        cout << d.query(q) << "\n";
    }
}
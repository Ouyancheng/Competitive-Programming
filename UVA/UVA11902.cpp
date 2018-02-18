#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;
vector<int> G[maxn];
bool a, vis[maxn];
int t, n;

bool can(int from, int inv, int to) {
    if(from == inv || vis[from]) {
        return 0;
    } else if(from == to) {
        return 1;
    }
    vis[from] = 1;
    for(auto v : G[from]) {
        if(can(v, inv, to)) {
            return 1;
        }
    }
    return 0;
}

void pformat() {
    cout << "+";
    for(int k = 0; k < n + n - 1; k++) {
        cout << "-";
    }
    cout << "+" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        cin >> n;
        fill(G, G + n, vector<int>());
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cin >> a;
                if(a) {
                    G[j].push_back(k);
                }
            }
        }
        for(int j = 0; j < n; j++) {
            pformat();
            for(int k = 0; k < n; k++) {
                fill(vis, vis + n, 0);
                bool can1 = can(0, j, k);
                fill(vis, vis + n, 0);
                bool can2 = can(0, -1, k);
                cout << "|" << (can1 || !can2 ? "N" : "Y");
            }
            cout << "|" << "\n";
        }
        pformat();
    }
    return 0;
}
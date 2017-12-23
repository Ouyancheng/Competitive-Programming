#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e2 + 5;
const int maxm = 5e2 + 5;

char g[maxn][maxm];
int n, m;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool can(int i, int j) {
    char dir = g[i][j];
    
    if(dir == 'N') {
        for(int k = i-1; k >= 0; k--) {
            if(valid(k,j) && g[k][j] != '.') {
                return 0;
            }
        }
    } else if(dir == 'S') {
        for(int k = i+1; k < n; k++) {
            if(valid(k,j) && g[k][j] != '.') {
                return 0;
            }
        }
    } else if(dir == 'W') {
        for(int k = j-1; k >= 0; k--) {
            if(valid(i,k) && g[i][k] != '.') {
                return 0;
            }
        }
    } else {
        for(int k = j+1; k < m; k++) {
            if(valid(i,k) && g[i][k] != '.') {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {
    bool has = 1;
    int ans = 0;
    
    while(has) {
        has = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == '.') {
                    continue;
                } else if(can(i,j)) {
                    has = 1;
                    ans++;
                    g[i][j] = '.';
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    
    cout << solve() << "\n";
}

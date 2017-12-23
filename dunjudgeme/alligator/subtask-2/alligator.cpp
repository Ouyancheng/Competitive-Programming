#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e3 + 5;
const int maxm = 2e3 + 5;

char g[maxn][maxm];
int c[maxn][maxm];
bool dn[maxn][maxm];
bool ds[maxn][maxm];
bool dw[maxn][maxm];
bool de[maxn][maxm];
int n, m;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void sweep() {
    for(int i = 0; i < n; i++) {
        for(int k = 0, from = 0, to = 0; k < m; k++) { // sweep to the east
            if(g[i][k] == 'W') {
                c[i][k] += from;
            }
            if(to) {
                dw[i][k] = 1;
            }
            if(g[i][k] == 'E') {
                to = 1;
            }
            if(g[i][k] != '.') {
                from++;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int k = m-1, from = 0, to = 0; k >= 0; k--) { // sweep to the west
            if(g[i][k] == 'E') {
                c[i][k] += from;
            }
            if(to) {
                de[i][k] = 1;
            }
            if(g[i][k] == 'W') {
                to = 1;
            }
            if(g[i][k] != '.') {
                from++;
            }
        }
    }
    
    for(int j = 0; j < m; j++) {
        for(int k = n-1, from = 0, to = 0; k >= 0; k--) { // sweep to the north
            if(g[k][j] == 'S') {
                c[k][j] += from;
            }
            if(to) {
                ds[k][j] = 1;
            }
            if(g[k][j] == 'N') {
                to = 1;
            }
            if(g[k][j] != '.') {
                from++;
            }
        }
    }
    
    for(int j = 0; j < m; j++) {
        for(int k = 0, from = 0, to = 0; k < n; k++) { // sweep to the south
            if(g[k][j] == 'N') {
                c[k][j] += from;
            }
            if(to) {
                dn[k][j] = 1;
            }
            if(g[k][j] == 'S') {
                to = 1;
            }
            if(g[k][j] != '.') {
                from++;
            }
        }
    }
}

void precompute(queue< pair<int,int> > &q) {
    sweep();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '.') {
                continue;
            } else if(c[i][j] == 0) {
                q.push({i,j});
            }
        }
    }
}

void relax(int i, int j, queue< pair<int,int> > &q) {
    char dir = g[i][j];
    if(dn[i][j]) {
        for(int k = i-1; k >= 0; k--) {
            if(valid(k,j) && g[k][j] == 'S') {
                c[k][j]--;
                if(c[k][j] == 0) {
                    q.push({k,j});
                }
            }
        }
    }
    
    if(ds[i][j]) {
        for(int k = i+1; k < n; k++) {
            if(valid(k,j) && g[k][j] == 'N') {
                c[k][j]--;
                if(c[k][j] == 0) {
                    q.push({k,j});
                }
            }
        }
    }
    
    if(dw[i][j]) {
        for(int k = j-1; k >= 0; k--) {
            if(valid(i,k) && g[i][k] == 'E') {
                c[i][k]--;
                if(c[i][k] == 0) {
                    q.push({i,k});
                }
            }
        }
    }
    
    if(de[i][j]) {
        for(int k = j+1; k < m; k++) {
            if(valid(i,k) && g[i][k] == 'W') {
                c[i][k]--;
                if(c[i][k] == 0) {
                    q.push({i,k});
                }
            }
        }
    }
}

int solve() {
    int ans = 0;
    queue< pair<int,int> > q;
    precompute(q);
    
    while((int) q.size() > 0) {
        pair<int,int> p = q.front();
        q.pop();
        ans++;
        relax(p.first, p.second, q);
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

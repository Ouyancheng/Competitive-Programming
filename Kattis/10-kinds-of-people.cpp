#include<iostream>

using namespace std;

int l,w,q;
int par[1000001];
int sa,sb,ea,eb;
char s[1001][1001];
bool vis[1000001];

int find(int x) { return (par[x] == x) ?  x : par[x] = find(par[x]); }
int idx(int r,int c) { return (r-1) * w + c; }

bool dfs(int i,int j,char c) {
    if(i > l || i <= 0 || j > w || j <= 0) return false;
    int cur = idx(i,j);
    if(vis[cur]) return false;
    if(c != s[i][j]) return false;

    vis[cur] = true;
    if(dfs(i-1,j,c)) par[find(cur)] = find(idx(i-1,j));
    if(dfs(i+1,j,c)) par[find(cur)] = find(idx(i+1,j));
    if(dfs(i,j-1,c)) par[find(cur)] = find(idx(i,j-1));
    if(dfs(i,j+1,c)) par[find(cur)] = find(idx(i,j+1));
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> w;
    
    for(int i = 1; i <= 1000000; i++) {
        par[i] = i;
    }

    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> s[i][j];
        }
    }
    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= w; j++) {
            dfs(i,j,'1');
            dfs(i,j,'0');
        }
    }

    cin >> q;
    while(q--) {
        cin >> sa >> ea >> sb >> eb;
        //cout << sa << ea << sb << eb << endl;
        if(s[sa][ea] == '0' && find(idx(sa,ea))==find(idx(sb,eb))) {
            cout << "binary" << "\n";
        } else if(s[sa][ea] == '1' && find(idx(sa,ea))==find(idx(sb,eb))) {
            cout << "decimal" << "\n";
        } else {
            cout << "neither" << "\n";
        }
    }
    //cout << idx(3,2) << endl;
    return 0;
}
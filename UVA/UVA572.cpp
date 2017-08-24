#include<iostream>

using namespace std;

char g[100][100];
bool vis[100][100];
int n,m;

void dfs(int i,int j) {
	if(i < 0 || i >= n || j < 0 || j >= m) return;
	if(g[i][j] == '*') return;
	if(vis[i][j]) return;
	vis[i][j] = 1;
	dfs(i-1,j); dfs(i+1,j); dfs(i,j-1); dfs(i,j+1);
	dfs(i-1,j-1); dfs(i+1,j+1); dfs(i-1,j+1); dfs(i+1,j-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m) {
		if(!n && !m) break;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> g[i][j];
				vis[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(g[i][j] != '*' && !vis[i][j]) {
					ans++;
					dfs(i,j);
				}
			}
		}
		cout << ans << "\n";
	}
}
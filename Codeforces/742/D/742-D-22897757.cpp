#include <iostream>
#include <vector>
#include <unordered_map>
//#define debug
using namespace std;

#define um unordered_map<int,int>
#define v32 vector<int>
#define mp make_pair

int n,m,w,a,b;

typedef struct woman {
	int w, b;
} woman;

woman ww[1005];
int par[1005];
int dp[1005][1005];
v32 gp[1005], rt;
um cw,cb;

int find(int x) { return (par[x]==x) ? x : par[x] = find(par[x]); }

int main(void) {
#ifdef debug
	freopen("in","r",stdin);
#else
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#endif
	cin >> n >> m >> w;

	for(int i = 1; i <= n; ++i) {
		cin >> ww[i].w;
		par[i] = i;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> ww[i].b;
	}
	for(int i = 1; i <= m; ++i) {
		cin >> a >> b;
		par[find(a)] = find(b);
	}
	rt.push_back(0);
	for(int i = 1 ; i <= n; ++i) {
		cw[find(i)] += ww[i].w;
		cb[find(i)] += ww[i].b;
		if(find(i)==i) rt.push_back(i);
		gp[find(i)].push_back(i);
	}
	for(int i = 1; i < rt.size(); ++i) {
		int p = rt[i]; v32 g = gp[p];
		for(int j = 0; j <= w; ++j) {
			if(cw[p]<=j) dp[i][j] = max(dp[i][j],dp[i-1][j-cw[p]]+cb[p]);
		}
		for(int e = 0; e < g.size(); ++e) {
			for(int j = 0; j <= w; ++j) {
				if(ww[g[e]].w<=j) dp[i][j] = max(dp[i][j],dp[i-1][j-ww[g[e]].w]+ww[g[e]].b);
			}
		}
		for(int j = 0; j <= w; ++j) dp[i][j] = max(dp[i][j],dp[i-1][j]);
	}
	int ans = 0;
	for(int i = 0; i <= w; i++) {
		ans = max(ans,dp[rt.size()-1][i]);
	}
	cout << ans << endl;
	return 0;
}
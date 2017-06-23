#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

#define p32 pair<int,int>
#define p64 pair<long long,int>
#define mp make_pair
#define INF 1LL<<60

int cc,n,m,s,t,p,a,b,c,ans;

long long fd[10001];
long long bd[10001];

vector< vector<p32> > fwd;
vector< vector<p32> > bwd;
priority_queue<p64,vector<p64>,greater<p64>> minhp;

void sp(int s, long long d[], vector< vector<p32> > alist) {
	minhp.push(mp(0,s));
	d[s] = 0;
	while(minhp.size()) {
		p64 e = minhp.top();
		minhp.pop();
		long long w = e.first; int u = e.second; 
		if(d[u] == w) {
			vector<p32> adj = alist[u];
			for(int i = 0; i < adj.size(); i++) {
				int v = adj[i].first; long long uv = adj[i].second;
				if(uv + w < d[v]) {
					d[v] = uv + w;
					minhp.push(mp(d[v],v));
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> cc;
	fwd.assign(10001,vector<p32>());
	bwd.assign(10001,vector<p32>());
	for(int i = 0; i < cc; i++) {
		cin >> n >> m >> s >> t >> p;
		ans = -1;
		for(int j = 1; j < n+1; j++) {
			fwd[j].clear(), bwd[j].clear();
			fd[j] = bd[j] = INF;
		}
		for(int j = 0; j < m; j++) {
			cin >> a >> b >> c;
			fwd[a].push_back(mp(b,c));
			bwd[b].push_back(mp(a,c));
		}
		sp(s,fd,fwd);
		sp(t,bd,bwd);
		for(int i = 1; i < n+1; i++) {
			vector<p32> adj = fwd[i];
			for(int j = 0; j < adj.size(); j++) {
				int v = adj[j].first, w = adj[j].second;
				if(fd[v] != INF && bd[i] != INF && \
					w + fd[i] + bd[v] <= p) {
						ans = max(ans,w);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
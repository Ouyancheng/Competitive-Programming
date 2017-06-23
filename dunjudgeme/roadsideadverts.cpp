#include<bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define ii pair<int,int>
#define MAX_V 500001
#define LOG_V 17

int n,q;
int a,b,c,d,e,eui=1;
vector<ii> v[MAX_V];
int lvl[2*MAX_V], vis[MAX_V], sum[MAX_V], par[MAX_V], euler[2*MAX_V], occ[MAX_V], ST[2*MAX_V][LOG_V], tmp[6];
vector<int> can;
vector< pair<int,ii> >edges;
unordered_set<int> us;

void computeST() {
	for(int i = 0; i < eui; i++) {
		ST[i][0] = i;
	}
	for(int j = 1; (1 << j) <= eui; j++) {
		for(int i = 0; (i + (1 << j) - 1) < eui; i++) {
			if(lvl[ST[i][j-1]] <= lvl[ST[i+(1<<(j-1))][j-1]]) {
				ST[i][j] = ST[i][j-1];
			} else {
				ST[i][j] = ST[i+(1<<(j-1))][j-1];
			}
		}
	}
}

int rmq(int a,int b) {
	int k = (int) log2(b-a+1);
	if(lvl[ST[a][k]] <= lvl[ST[b-(1<<k)+1][k]]) {
		return ST[a][k];
	} else {
		return ST[b-(1<<k)+1][k];
	}
}

int lca(int a,int b) {
	int x = occ[a], y = occ[b];
	if(x > y) swap(x,y);
	return euler[rmq(x,y)];
}

void dfslvl(int cur=1,int tot=0,int depth=1) {
	vis[cur] = 1;
	sum[cur] = tot;
	occ[cur] = eui;
	euler[eui] = cur;
	lvl[eui++] = depth;
	vector<ii> adj = v[cur];
	for(int i = 0; i < adj.size(); i++) {
		if(!vis[adj[i].fi]) {
			dfslvl(adj[i].fi,tot+adj[i].se,depth+1);
			euler[eui] = cur;
			lvl[eui++] = depth;
		}
	}
}

int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

int mst() {
	int ans = 0;
	sort(edges.begin(),edges.end());
	for(int i = 0; i < edges.size(); i++) {
		par[edges[i].se.fi] = edges[i].se.fi;
		par[edges[i].se.se] = edges[i].se.se;
	}
	for(int i = 0; i < edges.size(); i++) {
		int cost = edges[i].fi, u = edges[i].se.fi, v = edges[i].se.se;
		if(find(u) != find(v)) {
			par[find(u)] = find(v);
			ans += cost;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		a++, b++;
		v[a].eb(b,c);
		v[b].eb(a,c);
	}
	dfslvl();
	computeST();

	cin >> q;
	for(int i = 0; i < q; i++) {
		us.clear(); can.clear(); edges.clear();
		cin >> a >> b >> c >> d >> e;
		a++, b++, c++, d++, e++;
		tmp[1] = a, tmp[2] = b, tmp[3] = c, tmp[4] = d, tmp[5] = e;
		for(int u = 1; u <= 5; u++) can.eb(tmp[u]), us.insert(tmp[u]);
			for(int u = 1; u <= 4; u++) {
				for(int v = u+1; v <= 5; v++) {
					int node = lca(tmp[u],tmp[v]);
					if(us.find(node) == us.end()) {
						can.eb(node);
						us.insert(node);
					}
				}
			}
			for(int ui = 0; ui < can.size()-1; ui++) {
				for(int uj = ui+1; uj < can.size(); uj++) {
					int cost = sum[can[ui]]+sum[can[uj]] - (2 * sum[lca(can[ui],can[uj])]);
					edges.eb(cost,mp(can[ui],can[uj]));
				}
			}
			cout << mst() << "\n";
		}
		return 0;
	}
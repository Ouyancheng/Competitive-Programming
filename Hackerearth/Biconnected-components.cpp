#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define mp make_pair
#define eb emplace_back
#define em emplace
#define pp pop()
#define p32 pair<int,int>
#define p64 pair<ll,ll>
#define pdd pair<double,double>
#define fi first
#define se second
#define repn(i,e) for(int i = 0; i < e; i++)
#define repsn(i,s,e) for(int i = s; i < e; i++)
#define rrepn(i,s) for(int i = s; i >= 0; i--)
#define rrepsn(i,s,e) for(int i = s; i >= e; i--)
#define v64 vector<ll>
#define v32 vector<int>
#define vp64 vector<p64>
#define vp32 vector<p32>
#define aprint(a,s) if(DRAFT) repn(k,s) cout << setw(3) << right << a[k] << " "; cout << endl
#define mprint(aa,rn,cn) if(DRAFT) repn(i,rn) { aprint(aa[i],cn); cout << endl; }
#define vprint(a) if(DRAFT) repn(k,a.sz) cout << setw(3) << right << a[k] << " "; cout << endl
#define vvprint(a) if(DRAFT) repn(i,a.sz) { cout << i << ": "; repn(j,a[i].sz) { cout << a[i][j] << " "; } cout << endl; }
#define value(a) if(DRAFT) { cout << "DEBUG: The value of " << #a << " is " << a << endl; }
#define valuep(p) { if(DRAFT) cout << "( " << p.fi << ", " << p.se << " )" << endl; }
#define inf32 INT_MAX
#define inf64 LLONG_MAX
#define all(a) a.begin(),a.end()
#define UM unordered_map
#define US unordered_set
#define EPS 1e-10
#define breakl "\n"
#define MOD 1000000007
#define len(s) (int) s.length()
#define sz(v) (int) v.size()
 
#define MAX_N 15
 
inline void fastio(int debug) {
	if(debug) {
		cout << "DEBUGGING MODE..." << endl;
		freopen("in","r",stdin);
	} else {
		ios_base::sync_with_stdio(false), cin.tie(0);
	}
}
 
int n,a,b,distime,tot;
int dis[MAX_N], lo[MAX_N], vis[MAX_N], par[MAX_N], buf[MAX_N];
v32 graph[MAX_N];
int odd, even;
US<int> uniq;
stack<p32> st;
 
int DRAFT = 1;
 
void critical(int cur) {
	vis[cur] = 1;
	v32 adj = graph[cur];
	int sub = 0;
	dis[cur] = lo[cur] = ++distime;
	repn(i,sz(adj)) {
		if(!vis[adj[i]]) {
			sub++;
			par[adj[i]] = cur;
			st.em(cur,adj[i]);
			critical(adj[i]);
			lo[cur] = min(lo[cur],lo[adj[i]]);
			if((par[cur] == 0 && sub > 1) || (par[cur] != 0 && lo[adj[i]] >= dis[cur])) {
				while(sz(st)) {
					p32 edge = st.top();
					//valuep(edge);
					st.pop();
					uniq.insert(edge.fi);
					uniq.insert(edge.se);
					if(edge.fi == cur && edge.se == adj[i]) break;
				}
				//if(DRAFT) cout << breakl;
				if(sz(uniq)&1) odd++;
				else even++;
				uniq.clear();
			}
		} else if(par[cur] != adj[i] && dis[adj[i]] < dis[cur]) {
			st.em(cur,adj[i]);
			lo[cur] = min(lo[cur],dis[adj[i]]);
		}
	}
}
 
void init() {
	distime = tot = 0;
	repsn(i,1,n+1) {
		dis[i] = lo[i] = vis[i] = par[i] = 0;
	}
}
 
int e;
 
int main()
{
	fastio(0);
 
	cin >> n >> e;
 
	//init();
 
	repn(i,e) {
		cin >> a >> b;
		a++,b++;
		graph[a].eb(b);
		graph[b].eb(a);
	}
 
	repsn(i,1,n+1) {
		if(!vis[i]) {
			critical(i);
			while(sz(st)) {
				//valuep(st.top());
				p32 p = st.top();
				uniq.insert(p.fi);
				uniq.insert(p.se);
				st.pp;
			}
			if(sz(uniq)&1) odd++;
			else even++;
			uniq.clear();
		}
	}
	cout << odd << " " << even << breakl; 
	return 0;
}
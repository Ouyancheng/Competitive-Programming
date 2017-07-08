// Li Hong Sheng Gabriel's Competitive Programming Template v2017.6
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>

//using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define em emplace
#define len(s) (int) s.length()
#define sz(v) (int) v.size()
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
#define aprint(a,s) if(DRAFT) repn(k,s) cout << setw(4) << right << a[k] << " "; cout << endl
#define mprint(aa,rn,cn) if(DRAFT) repn(i,rn) { aprint(aa[i],cn); cout << endl; }
#define vprint(a) if(DRAFT) repn(k,sz(a)) cout << setw(4) << right << a[k] << " "; cout << endl
#define vsprint(a,b) if(DRAFT) repn(k,b) cout << setw(4) << right << a[k] << " "; cout << endl
#define vvprint(a) if(DRAFT) repn(i,sz(a)) { cout << i << ": "; repn(j,sz(a[i])) { cout << a[i][j] << " "; } cout << endl; }
#define vvsprint(a,b) if(DRAFT) repn(i,b) { cout << i << ": "; repn(j,sz(a[i])) { cout << a[i][j] << " "; } cout << endl; }
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

// Uncomment the include files, namespace and type to use
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AVL:
// set functions, rank and select:
//select: cout<<*X.find_by_order(>=1)<<endl;
//rank: cout<<X.order_of_key(>=1)<<endl;

inline void scale(int x) { cout.precision(x); cout << fixed; }
double dist(pdd x,pdd y) { return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)); }
ll lpow(ll x, int y) { if(!y)return 1;ll t=lpow(x,y/2);if(y&1)return(y>0)?x*t*t:(t*t)/x;return t*t; }
int ipow(int x, int y) { if(!y)return 1;int t=ipow(x,y/2);if(y&1)return(y>0)?x*t*t:(t*t)/x;return t*t; }

inline void fastio(int debug) {
	if(debug) {
		cout << "DEBUGGING MODE..." << endl;
		freopen("in","r",stdin);
	} else {
		ios_base::sync_with_stdio(false), cin.tie(0);
	}
}

// End of Template

#define MAX_V 100005
#define LOG_V 18

bool DRAFT = 1;

// Variables for LCA
int v,logv;
vector< pair<int,int> > LCAGraph[MAX_V];
int lvl[MAX_V], par[MAX_V], ST[MAX_V][LOG_V], sum[MAX_V];

void addLCAEdge(int u,int v,int w=0) {
	LCAGraph[u].emplace_back(v,w);
	LCAGraph[v].emplace_back(u,w);
}

int LCA(int a,int b) {
	if(lvl[a] < lvl[b]) swap(a,b);

	for(int i = floor(log2(lvl[a])); i >= 0; i--) {
		if(lvl[a] - (1 << i) >= lvl[b]) {
			a = ST[a][i];
		}
	}
	if(a == b) return a;
	for(int i = logv-1; i >= 0; i--) {
		if(ST[a][i] != -1 && ST[a][i] != ST[b][i]) {
			a = ST[a][i], b = ST[b][i];
		}
	}
	return par[a];
}

int kthAncestor(int a,int k=0) {
	int pos = lvl[a]-k-1;
	for(int i = floor(log2(lvl[a])); i >= 0; i--) {
		if(a == -1) break;
		if(lvl[a] - (1 << i) >= pos) {
			a = ST[a][i];
		}
	}
	return a;
}

int kthNodeOnPath(int a,int b,int k) {
	if(k < 2) return a;
	int u = LCA(a,b);
	int d1 = lvl[a] - lvl[u];
	int d2 = lvl[b] - lvl[u];
	if(d1+1 >= k) {
		return kthAncestor(a,k-2);
	} else if(d2 >= k-d1-1) {
		if(d2-(k-d1-1)-1 < 0) return b;
		return kthAncestor(b,d2-(k-d1-1)-1);
	}
	return -1;
}

int treeDist(int a,int b) {
	int u = LCA(a,b);
	return sum[a] + sum[b] - 2 * sum[u];
}

void buildLCATree(int cur=0,int anc=-1,int depth=1,int total=0) {
	lvl[cur] = depth;
	par[cur] = ST[cur][0] = anc;
	sum[cur] = total;
	for(int i = 1; (1 << i) < lvl[cur]; i++) {
		ST[cur][i] = ST[ST[cur][i-1]][i-1];
	}
	for(int i = 0; i < (int) LCAGraph[cur].size(); i++) {
		if(LCAGraph[cur][i].first != anc) {
			buildLCATree(LCAGraph[cur][i].first,cur,depth+1,total+LCAGraph[cur][i].second);
		}
	}
}

void resetLCA() {
	fill(LCAGraph,LCAGraph+MAX_V,vector< pair<int,int> >());
	memset(par,0,sizeof(par));
	for(int i = 0; i < MAX_V; i++) {
		for(int j = 0; j <= LOG_V-1; j++) {
			ST[i][j] = -1;
		}
	}
}

// user-defined functions

void addLeaf(int x,int y) {
	if(y == -1) {
		lvl[x] = 1;
	} else {
		lvl[x] = lvl[y]+1;
	}
	par[x] = ST[x][0] = y;
	for(int i = 1; (1 << i) < lvl[x]; i++) {
		ST[x][i] = ST[ST[x][i-1]][i-1];
	}
}

int t,x,y,q,a,rt;
int has[MAX_V];

int main(void) {
	fastio(0);
	cin >> t;
	while(t--) {
		cin >> v;
		logv = floor(log2(v))+1;
		memset(has,0,sizeof(has));
		resetLCA();
		repn(i,v) {
			cin >> x >> y;
			x--, y--;
			if(y < 0) {
				rt = x;
				continue;
			}
			addLCAEdge(x,y);
			has[x] = has[y] = 1;
		}
		buildLCATree(rt);
		cin >> q;
		repn(i,q) {
			cin >> a;
			if(a == 0) {
				cin >> y >> x;
				has[x-1] = 1;
				addLeaf(--x,--y);
			} else if(a == 2) {
				cin >> x >> y;
				if(has[x-1] == 0 || y >= lvl[x-1]) cout << 0 << breakl;
				else cout << kthAncestor(--x,--y)+1 << breakl;
			} else {
				cin >> x;
				has[x-1] = 0;
			}
		}
	}
	return 0;
}
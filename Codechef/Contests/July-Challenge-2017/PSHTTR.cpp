// Li Hong Sheng Gabriel's Competitive Programming Template v2017.8
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
#define aprint(a,s) if(DRAFT) { cout << "DEBUG: "; repn(k,s) { cout << setw(4) << right << a[k] << " "; } cout << endl; }
#define mprint(aa,rn,cn) if(DRAFT) { repn(i,rn) { aprint(aa[i],cn); } cout << endl; }
#define vprint(a) if(DRAFT) { cout << "DEBUG: "; repn(k,sz(a)) { cout << setw(4) << right << a[k] << " "; } cout << endl; }
#define vrprint(a,b) if(DRAFT) { cout << "DEBUG: "; repn(k,b) { cout << setw(4) << right << a[k] << " "; } cout << endl; }
#define vvprint(a) if(DRAFT) repn(i,sz(a)) { cout << "DEBUG: " << i << ": "; repn(j,sz(a[i])) { cout << setw(4) << right << a[i][j] << " "; } cout << endl; }
#define vvrprint(a,b) if(DRAFT) repn(i,b) { cout << "DEBUG: " << i << ": "; repn(j,sz(a[i])) { cout << setw(4) << right << a[i][j] << " "; } cout << endl; }
#define value(a) if(DRAFT) { cout << "DEBUG: The value of " << #a << " is " << a << endl; }
#define valuep(p) { if(DRAFT) cout << "DEBUG: " << "( " << p.fi << ", " << p.se << " )" << endl; }
#define message(s) { if(DRAFT) cout << "MESSAGE: " << s << endl; }
#define inf32 INT_MAX
#define inf64 LLONG_MAX
#define all(a) a.begin(),a.end()
#define UM unordered_map
#define US unordered_set
#define EPS 1e-10
#define breakl "\n"
#define MOD 1000000007
#define lcstring(s) transform(all(s), s.begin(), ::tolower)
#define ucstring(s) transform(all(s), s.begin(), ::toupper)
#define lcchar(c) ((char) tolower(c))
#define ucchar(c) ((char) toupper(c))

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

void split(vector<string> &tmp,string &line,char * buffer,char delim=' ') {
	strcpy(buffer,line.c_str()); // buffer length must be at least |line| + 1
	char * token = strtok(buffer,&delim);
	while(token != 0) {
		tmp.eb(string(token));
		token = strtok(NULL,&delim);
	}
}

inline void fastio(int debug) {
	if(debug) {
		cout << "DEBUGGING MODE..." << endl;
		freopen("in","r",stdin);
	} else {
		ios_base::sync_with_stdio(false), cin.tie(0);
	}
}

// End of Template

bool DRAFT = 1; // DO NOT REMOVE THIS LINE

#define MAX_N 100005
#define LOG_N 18

// Variables for HLD algorithm
int ssz[MAX_N], pos[MAX_N], id[MAX_N], head[MAX_N], chainlen[MAX_N];
vector< vector< pair<int,int> > > tree;
int ptr,segpos;

// Variables for LCA algorithm
int eui = 1;
int lvl[2*MAX_N], par[MAX_N], euler[2*MAX_N], occ[MAX_N], ST[2*MAX_N][LOG_N];

// variables for fenwick tree
int FT[MAX_N];

// User defined variables: variable n is used by the HLD algorithm
int n,m,t,u,v,c,k,esz;
pair<int,p32> edges[MAX_N];
pair<p32,p32> queries[MAX_N];
int ans[MAX_N];

/////////////////////////////////////// Start of Fenwick tree functions ///////////////////////////////////////////

int queryFT(int i) {
	int c = i;
	int ans = 0;
	while(c >= 1) {
		ans ^= FT[c];
		c -= c & -c;
	}
	return ans;
}

void updateFT(int i,int d) {
	int c = i;
	while(c <= n) {
		FT[c] ^= d;
		c += c & -c;
	}
}

///////////////////////////////////////// Start of LCA functions /////////////////////////////////////////////
void computeSparseTable() {
	for(int i = 1; i <= eui; i++) {
		ST[i][0] = i;
	}
	for(int j = 1; (1 << j) <= eui; j++) {
		for(int i = 1; (i + (1 << j) - 1) <= eui; i++) {
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

int LCA(int a,int b) {
	int x = occ[a], y = occ[b];
	if(x > y) swap(x,y);
	return euler[rmq(x,y)];
}

void dfslvl(int cur=1,int pre=0,int depth=1) {
	ssz[cur] = 1;
	occ[cur] = eui;
	par[cur] = pre;
	euler[eui] = cur;
	lvl[eui++] = depth;
	vector< pair<int,int> > adj = tree[cur];
	int s1 = (int) adj.size();
	for(int i = 0; i < s1; i++) {
		pair<int,int> pp = adj[i];
		int v = pp.first, c = pp.second;
		if(v != pre) {
			edges[esz++] = mp(c,mp(cur,v));
			dfslvl(v,cur,depth+1);
			ssz[cur] += ssz[v];
			euler[eui] = cur;
			lvl[eui++] = depth;
		}
	}
}

void buildLCATree(int u=1) {
	dfslvl(u);
	computeSparseTable();
}

///////////////////////////////////////// Start of HLD functions /////////////////////////////////////////////
void HLD(int u=1,int p=0,int w=0,int chead=0) {
	int weight = -1, heavy = u;
	head[id[u]] = (chead ? chead : u);
	pos[u] = ++segpos;
	chainlen[id[u]]++;
	vector< pair<int,int> > adj = tree[u];
	int s1 = (int) adj.size();
	for(int i = 0; i < s1; i++) {
		pair<int,int> pp = adj[i];
		int v = pp.first, wt = pp.second;
		if(v != p && ssz[v] > weight) {
			weight = ssz[v];
			heavy = v;
		}
	}
	if(weight != -1) {
		id[heavy] = id[u];
		HLD(heavy,u,weight,head[id[u]]);
	}
	for(int i = 0; i < s1; i++) {
		pair<int,int> pp = adj[i];
		int v = pp.first, wt = pp.second;
		if(v != p && v != heavy) {
			id[v] = ++ptr;
			HLD(v,u,wt);
		}
	}
}

// Adds undirected edge to HLD tree
// a,b and c represents src,dst and cost respectively
void addHLDEdge(int a,int b,int c=0) {
	tree[a].push_back(make_pair(b,c));
	tree[b].push_back(make_pair(a,c));
}

void resetHLD() {
	esz = segpos = ptr = 0;
	eui = 1;
	tree.assign(n+2,vector< pair<int,int> >());
	memset(FT,0,sizeof(FT));
}

// user-defined functions
int solve(int u,int v) {
	int top = head[id[u]], bot = u, ancestor = LCA(u,v);
	int ans = 0;
	int aval = queryFT(pos[ancestor]);

	while(id[top] != id[ancestor]) {
		ans ^= (queryFT(pos[bot]) ^ queryFT(pos[top]-1));
		bot = par[top];
		top = head[id[bot]];
	}
	ans ^= (queryFT(pos[bot])^aval);

	top = head[id[v]], bot = v;

	while(id[top] != id[ancestor]) {
		ans ^= (queryFT(pos[bot]) ^ queryFT(pos[top]-1));
		bot = par[top];
		top = head[id[bot]];
	}
	ans ^= (queryFT(pos[bot])^aval);
	return ans;
}

int main() {
	fastio(0);
	cin >> t;
	while(t--) {
		int cur = 0;
		cin >> n;
		resetHLD();
		repn(i,n-1) {
			cin >> u >> v >> c;
			addHLDEdge(u,v,c);
		}
		buildLCATree();
		HLD();
		sort(edges,edges+n-1);

		cin >> m;
		repn(i,m) {
			cin >> u >> v >> k;
			queries[i] = mp(mp(k,i),mp(u,v));
		}
		sort(queries,queries+m);
		repn(i,m) {
			int mqNum = queries[i].fi.fi; bool flag = false;
			while(cur < n-1 && edges[cur].fi <= mqNum) {
				int pinf = pos[edges[cur].se.se], cid = id[edges[cur].se.se];
				updateFT(pinf,edges[cur].fi);
				cur++;
			}
			while(i < m && mqNum == queries[i].fi.fi) {
				ans[queries[i].fi.se] = solve(queries[i].se.fi,queries[i].se.se);
				i++;
				flag = true;
			}
			if(flag) i--;
		}
		repn(i,m) {
			cout << ans[i] << breakl;
		}
	}
	return 0;
}  
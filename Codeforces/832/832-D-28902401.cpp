// Li Hong Sheng Gabriel's Competitive Programming Template v2017.9
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
#define dmsg(s) { if(DRAFT) cout << "MESSAGE: " << s << endl; }
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
#define islcchar(c) (c >= 'a' && c <= 'z')
#define isucchar(c) (c >= 'A' && c <= 'Z')

// Uncomment the include files, namespace and type to use
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AVL:
// set functions, rank and select:
//select: cout<<*X.find_by_order(>=1)<<endl;
//rank: cout<<X.order_of_key(>=1)<<endl;

inline void scale(int x) { cout.precision(x); cout << fixed; }
//double dist(pdd x,pdd y) { return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)); }
ll lpow(ll x, int y) { if(!y)return 1;ll t=lpow(x,y/2);if(y&1)return(y>0)?x*t*t:(t*t)/x;return t*t; }
int ipow(int x, int y) { if(!y)return 1;int t=ipow(x,y/2);if(y&1)return(y>0)?x*t*t:(t*t)/x;return t*t; }

void split(vector<string> &tmp,string &line,char * buffer,char delim=' ') {
	strcpy(buffer,line.c_str()); // buffer length must be at least |line| + 1
	char * token = strtok(buffer,&delim);
	while(token != 0) {
		tmp.eb(string(token)); // tokens are stored in tmp vector
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

bool DRAFT = 0; // DO NOT REMOVE THIS LINE

#define MAX_N 100005
#define LOG_N 18

// Variables for LCA algorithm
int eui = 1;
int lvl[2*MAX_N], par[MAX_N], euler[2*MAX_N], occ[MAX_N], ST[2*MAX_N][LOG_N];
vector< pair<int,int> > tree[MAX_N];

// User defined variables: variable n is used by the HLD algorithm
int n,a,b,c,t,d,p=2;

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
	occ[cur] = eui;
	par[cur] = pre;
	euler[eui] = cur;
	lvl[eui++] = depth;
	vector< pair<int,int> > adj = tree[cur];
	int s1 = (int) adj.size();
	for(int i = 0; i < s1; i++) {
		pair<int,int> pp = adj[i];
		int v = pp.first;
		if(v != pre) {
			dfslvl(v,cur,depth+1);
			euler[eui] = cur;
			lvl[eui++] = depth;
		}
	}
}

void buildLCATree(int u=1) {
	dfslvl(u);
	computeSparseTable();
}

// user-defined functions

int dist(int a,int b) {
	return lvl[occ[a]] + lvl[occ[b]] - 2 * lvl[occ[LCA(a,b)]] + 1;
}

int calc(int a,int b,int c) {
	return (dist(a,b) + dist(b,c) - dist(a,c) + 1)/2;
}

int main(void) {
	fastio(0);
	cin >> n >> d;
	
	repn(i,n-1) {
		cin >> a;
		tree[p].eb(mp(a,0));
		tree[a].eb(mp(p,0));
		p++;
	}
	buildLCATree(2);
	
	repn(i,d) {
		cin >> a >> b >> c;
		int ans1 = calc(a,b,c);
		int ans2 = calc(b,a,c);
		int ans3 = calc(a,c,b);
		cout << max(ans1,max(ans2,ans3)) << breakl;
	}
	return 0;
}
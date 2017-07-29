// Solution for UVA11733 Airport
// Solution sketch:
// First, we use MST algorithm to find (minimum number of) minimum spanning forests
// Observe that between every 2 nodes we need at most 1 edge (more edges are redundant anyway)
// Also the graph may not be connected. Hence, we may obtain forests. We need to find the
// minimum cost of each forest (sum of its edges) because we only want the min cost edges between nodes.
// Furthermore, we need to minimize the number of such forests because we want to share airports as much
// as possible. In other words, we want to minimize the number of components in the graph.
// Second, the previous step ensures that we will get the optimal solution given that airports are
// cheaper than building roads (adding edges). However, airports are not always cheaper than building roads.
// Also, we are obliged to build at least 1 airport in each component. So we can take airport-cost*|components|
// to be our base cost.
// Furthermore, we have to check if each road in a component to see if its cost is STRICTLY worse than constructing
// an airport so that we can take the more protfitable option. We use the STRICTLY worse condition because
// we are obliged to find the option that uses more airports among those that have the same minimal cost.
// Using this inequality, we will build airports rather than roads if both cost the same.
// Add the cost of building additional roads and airports to our base cost to obtain the answer.

// Solution complexity: O(M*log(M)) using Kruskal's MST algorithm (where M is the number of edges)

// Li Hong Sheng Gabriel's Competitive Programming Template v2017.10
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
#define aprint(a,s) if(DRAFT) { cout << "DEBUG: "; repn(kk,s) { cout << setw(4) << right << a[kk] << " "; } cout << endl; }
#define mprint(aa,rn,cn) if(DRAFT) { repn(i,rn) { aprint(aa[i],cn); } cout << endl; }
#define vprint(a) if(DRAFT) { cout << "DEBUG: "; repn(kk,sz(a)) { cout << setw(4) << right << a[kk] << " "; } cout << endl; }
#define vrprint(a,b) if(DRAFT) { cout << "DEBUG: "; repn(kk,b) { cout << setw(4) << right << a[kk] << " "; } cout << endl; }
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

void toBin(int a,int len) {
	v32 v;
	while(a) { v.eb(a&1), a >>= 1; }
	while(sz(v) < len) v.eb(0);
	reverse(all(v));
	for(auto p : v) cout << p; cout << endl;
}

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

bool DRAFT = 1; // DO NOT REMOVE THIS LINE

#define MAX_N 10006

int arr[MAX_N], par[MAX_N];
int comp,n,m,a,x,y,c,t;
ll ans1,ans2;
vector<pair<int,p32>> v;

int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

int main(void) {
	fastio(0);
	cin >> t;
	repsn(cc,1,t+1) {
		ans1 = ans2 = 0;
		v.clear();
		cin >> n >> m >> a;
		comp = n;
		repsn(i,1,n+1) par[i] = i;
		repn(i,m) {
			cin >> x >> y >> c;
			v.eb(mp(c,mp(x,y)));
		}
		sort(all(v));
		repn(i,m) {
			if(comp == 1) break;
			int aa = v[i].fi, bb = v[i].se.fi, cc = v[i].se.se;
			if(find(bb) != find(cc)) {
				comp--;
				par[find(bb)] = find(cc);
				if(aa < a) ans1 += aa;
				else ans1 += a, ans2++;
			}
		}
		ans1 += (1LL * comp * a); ans2 += comp;
		cout << "Case #" << cc << ": " << ans1 << " " << ans2 << breakl;
	}
	return 0;
}

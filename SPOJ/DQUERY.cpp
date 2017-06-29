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
#define pp pop()
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

bool DRAFT = 1;

#define MAX_E 1000003
#define MAX_Q 200003
#define MAX_N 30003

int n,a,b,q,cur=1;
int f[MAX_N], arr[MAX_N], pre[MAX_E], out[MAX_Q];
pair<int,p32> query[MAX_Q];

int queryFT(int i, int f[]) {
	int c = i;
	int ans = 0;
	while(c) {
		ans += f[c];
		c -= c & -c;
	}
	return ans;
}

void addFT(int d,int i,int f[],int N) {
	int c = i;
	while(c <= N) {
		f[c] += d;
		c += c & -c;
	}
}

int main(void) {
	fastio(0);
	cin >> n;
	repsn(i,1,n+1) cin >> arr[i];
	cin >> q;
	repsn(i,1,q+1) {
		cin >> a >> b;
		query[i] = mp(b,mp(a,i));
	}
	sort(query+1,query+q+1);
	fill(pre,pre+MAX_E,-1);
	repsn(i,1,n+1) {
		if(pre[arr[i]] != -1)
			addFT(-1,pre[arr[i]],f,n);
		addFT(1,pre[arr[i]]=i,f,n);
		while(cur <= q && query[cur].fi == i) {
			out[query[cur].se.se] = queryFT(query[cur].fi,f)-queryFT(query[cur].se.fi-1,f);
			cur++;
		}
		if(cur > q) break;
	}
	repsn(i,1,q+1) cout << out[i] << breakl;
	return 0;
}

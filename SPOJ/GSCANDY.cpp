// Li Hong Sheng Gabriel's Competitive Programming Template v2017.5
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>

//using namespace __gnu_pbds;
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

// Uncomment the include files, namespace and type to use
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AvL:
// set functions, rank and select:
//select: cout<<*X.find_by_order(>=1)<<endl;
//rank: cout<<X.order_of_key(>=1)<<endl;

inline void scale(int x) { cout.precision(x); cout << fixed; }
double dist(pdd x,pdd y) { return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)); }

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

int n, t, arr[1000], dp[1000][1001], ptr[1000];
UM<int,int> fw;

int f(int i=0,int j=1) {
	if(i >= n || j > n) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = j+max(f(i+1),f(ptr[i],j+1));
}

int main(void) {
	fastio(0);
	cin >> t;
	while(t--) {
		cin >> n;
		fw.clear();
		repn(i,n) {
			cin >> arr[i];
			fw[arr[i]] = n;
		}
		repn(i,n) repsn(j,1,n+1) dp[i][j] = -1;
		rrepn(i,n-1) {
			ptr[i] = fw[arr[i]];
			fw[arr[i]] = i;
		}
		cout << f() << breakl;
	}

	return 0;
}

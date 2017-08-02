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

int lps[1005][1005];
string grid[1005];
string pat;
int r,c,m,n,t;
set<p32> has[1005];

// Pre-condition:
// lps array must be precalculated using s
// s: arbitrary string
// pat: arbitrary string
// Post-codition: prints all occurences of pat in s using kmp
void KMP(string &s,string &pat,int row,int prow) {
	int i = 0, j = 0, ans = 0;
	int l1 = (int) s.length(), l2 = (int) pat.length();

	while(i < l1) {
		if(s[i] == pat[j]) {
			i++,j++;
			if(j == l2) {
				if(!prow || has[prow-1].find(mp(row-1,i-j)) != has[prow-1].end()) has[prow].insert(mp(row,i-j));
				ans++;
				j = lps[j-1][prow];
			}
		} else {
			if(j>0) {
				j = lps[j-1][prow];
			} else {
				i++;
			}
		}
	}
}

// Pre-condition:
// lps array must exist
// pat: arbitrary string
// Post-condition: Precalculates lps using pat
void buildKMP(string &pat,int row) {
	int i = 1, len = 0, l1 = (int) pat.length();
	lps[0][row] = 0;
	while(i < l1) {
		if(pat[len] == pat[i]) {
			lps[i++][row] = ++len;
		} else {
			if(len > 0) {
				len = lps[len-1][row];
			} else {
				lps[i++][row] = 0;
			}
		}
	}
}

int main(void) {
	fastio(0);
	cin >> t;
	while(t--) {
		cin >> n >> m; 
		repn(i,n) cin >> grid[i];
		cin >> r >> c;
		fill(has,has+r,set<p32>());
		repn(i,r) {
			cin >> pat;
			buildKMP(pat,i);
			repsn(ii,i,n-r+i+1) KMP(grid[ii],pat,ii,i);
            if(sz(has[i])==0) {
                repsn(j,i+1,r) cin >> pat;
                break;
            }
		}
		if(sz(has[r-1])) cout << "YES" << breakl;
		else cout << "NO" << breakl;
	}
	return 0;
}
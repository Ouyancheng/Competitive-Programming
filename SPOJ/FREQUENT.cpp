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
 
void split(vector<string> &tmp,string &line) {
	stringstream ss(line); string s;
	while(ss >> s) tmp.eb(s);
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
#define MAX_Q 100005
#define OFFSET 100000
 
int n,q,block,pre;
int arr[MAX_N],B[MAX_Q],s[MAX_Q],e[MAX_Q],f[2*MAX_N];
p32 o[MAX_Q];
 
bool cmp(int i,int j) {
	if(s[i]/block < s[j]/block)
		return true;
	else if(s[i]/block == s[j]/block)
		return e[i] < e[j];
	return false;
}
 
int main(void) {
	fastio(0);
	while(cin >> n && n) {
		block = (int) ceil(sqrt(n));
		cin >> q;
		repn(i,n) cin >> arr[i];
		repn(i,q) {
			cin >> s[i] >> e[i];
			s[i]--, e[i]--;
			B[i] = i;
		}
		sort(B,B+q,cmp);
 
		for(int i = 0, ans = 0, rb = 0, pre = -1, rs = 0, ansi = -1, rsi = -1; i < q; i++) {
			int lb = s[B[i]]/block, nx = lb * block + block;
			if(lb != pre) {
				memset(f,0,sizeof f);
				rb = lb * block + block - 1;
				rs = 0; rsi = -1;
			}
			ansi = rsi, ans = rs;
			repsn(fi,rb+1,e[B[i]]+1) {
				f[arr[fi]+OFFSET]++, rb++;
				if(f[arr[fi]+OFFSET] > rs) {
					rs = f[arr[fi]+OFFSET];
					rsi = fi;
					if(rs > ans) {
						ansi = rsi;
						ans = rs;
					}
				}
			}
			repsn(bi,s[B[i]],min(e[B[i]]+1,nx)) {
				if(++f[arr[bi]+OFFSET] > ans) {
					ansi = bi;
					ans = f[arr[bi]+OFFSET];
				}
			}
			o[B[i]] = mp(ans,ansi);
			repsn(bi,s[B[i]],min(e[B[i]]+1,nx)) {
				f[arr[bi]+OFFSET]--;
			}
			pre = lb;
		}
		repn(i,q) cout << o[i].fi << breakl;
	}
	return 0;
}
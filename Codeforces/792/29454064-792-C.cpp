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
#define brkl "\n"
#define MOD 1000000007
#define lcstr(s) transform(all(s), s.begin(), ::tolower)
#define ucstr(s) transform(all(s), s.begin(), ::toupper)
#define lcch(c) ((char) tolower(c))
#define ucch(c) ((char) toupper(c))
#define islcch(c) (c >= 'a' && c <= 'z')
#define isucch(c) (c >= 'A' && c <= 'Z')

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
	stringstream ss(line); string s; tmp.clear();
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

////////////////////////////////////// End of Template /////////////////////////////////////////////

bool DRAFT = 1; // DO NOT REMOVE THIS LINE

string s;
v32 num;
int dp[100005][3];
pair<bool,p32> out[100005][3];
const int oo = 1e9;

int f(int cur,int mod,bool nz) {
	if(cur == sz(num)) return (nz && mod == 0) ? 0 : oo;
	if(dp[cur][mod] != -1) return dp[cur][mod];
	if(cur == sz(num)-1) {
		if(num[cur]%3==mod) {
			out[cur][mod] = mp(1,mp(cur,mod));
			return dp[cur][mod] = 0;
		} else if(mod == 0) {
			out[cur][mod] = mp(0,mp(cur,mod));
			return dp[cur][mod] = 1;
		}
		return oo;
	}
	if(!nz && num[cur] == 0) {
		dp[cur][mod] = 1+f(cur+1,mod,nz);
		out[cur][mod] = mp(0,mp(cur+1,mod));
		return dp[cur][mod];
	}
	int res1 = f(cur+1,(mod-num[cur]+9)%3,nz|num[cur]), res2 = 1+f(cur+1,mod,nz);
	dp[cur][mod] = min(res1,res2);
	if(res1 < res2) out[cur][mod] = mp(1,mp(cur+1,(mod-num[cur]+9)%3));
	else out[cur][mod] = mp(0,mp(cur+1,mod));
	return dp[cur][mod];
}

int main(void) {
	fastio(0);

	cin >> s;
	repn(i,len(s)) repn(j,4) dp[i][j] = -1;
	repn(i,len(s)) num.eb(s[i]-'0');
	int res1 = oo, res2 = oo;
	if(num[0] == 0) {
		res1 = res2 = 1+f(1,0,0);
	} else {
		res1 = f(1,(9-num[0])%3,num[0]), res2 = 1+f(1,0,0);
	}
	int ans = min(res1,res2);
	if(ans >= len(s) && s.find_first_of('0') == string::npos) {
		cout << -1;
	} else if(ans >= len(s)) {
		cout << 0;
	} else {
		int cur = -1, mod = -1, t; string ss;
		if(res1<res2) {
			cur = 1, mod = (9-num[0])%3;
			cout << to_string(num[0]);
		} else {
			cur = 1, mod = 0;
		}
		while(1) {
			if(out[cur][mod].fi) cout << num[cur];
			if(out[cur][mod].se.fi == cur && out[cur][mod].se.se == mod) break;
			t = cur, cur = out[t][mod].se.fi, mod = out[t][mod].se.se;
		}
		//assert(len(ss) == len(s)-ans);
	}
	cout << brkl;
	return 0;
}

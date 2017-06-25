// Li Hong Sheng Gabriel's Competitive Programming Template v2017.3

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <queue>
#include <cmath>
#include <set>
#include <cstdlib>
#include <utility>
#include <queue>
#include <functional>
#include <sstream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>

//using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define sz size()
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
#define INF32 INT_MAX
#define INF64 LLONG_MAX
#define um unordered_map
#define us unordered_set
#define breakl "\n"

// Uncomment the include files, namespace and type to use
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AVL:
// set functions, rank and select:
//select: cout<<*X.find_by_order(>=1)<<endl;
//rank: cout<<X.order_of_key(>=1)<<endl;

inline void scale(int x) { cout.precision(x); cout << fixed; }
double dist(pdd x,pdd y) { return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)); }
//int find(int x) { return (par[x]==x) ? x : par[x]=find(par[x]);}
inline void fastio(int debug) {
	if(debug) {
		cout << "DEBUGGING MODE..." << endl;
		freopen("in","r",stdin);
	} else {
		ios_base::sync_with_stdio(false), cin.tie(0);
	}
}

// End of Template

bool DRAFT = 0;

int fwdlcs[2101][2101], bklcs[2101][2101];
p32 fwdlcp[2101],bklcp[2101];
string s1, s2;
int ops;
int t1[26];
vp32 res;

void precalc(int lcs[][2101]) {
	rrepn(i,s2.length()-1) {
		rrepn(j,s1.length()-1) {
			if(s2[i] == s1[j]) {
				lcs[i][j] = 1 + lcs[i+1][j+1];
			}
		}
	}
}

void go(int lcs[][2101],p32 lcp[]) {
	p32 tmp;
	repn(i,s2.length()) {
		tmp = mp(0,0);
		repn(j,s1.length()) {
			tmp = max(tmp,mp(lcs[i][j],j));
		}
		lcp[i] = tmp;
	}
}

int main(void) {
	fastio(0);
	cin >> s1 >> s2;
	repn(i,s1.length()) {
		t1[s1[i]-'a']++;
	}
	repn(i,s2.length()) {
		if(t1[s2[i]-'a']==0) {
			cout << "-1";
			cout << breakl;
			return 0;
		}
	}
	precalc(fwdlcs);
	reverse(s1.begin(),s1.end());
	precalc(bklcs);
	go(fwdlcs,fwdlcp), go(bklcs,bklcp);

	repn(i,s2.length()) {
		if(fwdlcp[i].fi >= bklcp[i].fi) {
			res.pb(mp(fwdlcp[i].se+1,fwdlcp[i].se+fwdlcp[i].fi));
		} else {
			res.pb(mp(s1.length()-bklcp[i].se,s1.length()-(bklcp[i].se+bklcp[i].fi-1)));
		}
		i += max(fwdlcp[i].fi,bklcp[i].fi) - 1;
		ops++;
	}
	cout << ops << breakl;
	repn(i,res.size()) {
		cout << res[i].fi << " " << res[i].se << breakl;
	}
	return 0;
}
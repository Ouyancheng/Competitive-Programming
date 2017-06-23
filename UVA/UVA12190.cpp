// Li Hong Sheng Gabriel's Competitive Programming Template v2016.2

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
#include <set>
#include <cstdlib>
#include <utility>
#include <queue>
#include <functional>
#include <unordered_set>
#include <sstream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>

//using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define valid(r,c,rn,cn) (r >= 0 && c >= 0 && r < rn && c < cn)
#define ntc(a) (char) (a + 'A')
#define ctn(a) a - 65
#define mp make_pair
#define pb push_back
#define sz size()
#define pp pop()
#define p32 pair<int,int>
#define p64 pair<ll,ll>
#define pdd pair<double,double>
#define fi first
#define se second
#define tse se.fi
#define th se.se
#define tri pair<double,pdd>
#define repn(i,e) for(int i = 0; i < e; i++)
#define repsn(i,s,e) for(int i = s; i < e; i++)
#define rrepn(i,s) for(int i = s; i >= 0; i--)
#define rrepsn(i,s,e) for(int i = s; i >= e; i--)
#define v64 vector<ll>
#define v32 vector<int>
#define vp64 vector<p64>
#define vp32 vector<p32>
#define vtri vector<tri>
#define vprint(a,s) repn(k,s) cout << setw(3) << right << a[k] << " "; cout << endl
#define mprint(a,rn,cn) repn(i,rn) { vprint(a[i],cn); cout << endl; }
#define dmprint(a,s) repn(i,s) { cout << i << ": "; repn(j,g[i].sz) { cout << g[i][j] << " "; } cout << endl; }
#define INF32 INT_MAX
#define INF64 LLONG_MAX
#define dsc greater
#define pq priority_queue
#define minhp pq<p32,v32,dsc<p32>>
#define maxhp pq<int>
#define gcd __gcd
#define lcm(x,y) (x*y)/gcd(x,y)

// Uncomment the include files, namespace and type to use
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AVL:
// set functions, rank and select:
//select: cout<<*X.find_by_order(>=1)<<endl;
//rank: cout<<X.order_of_key(>=1)<<endl;

inline void setscale(int x) { cout.precision(x); cout << fixed; }
inline void pp32(p32 p) { cout << "( " << p.fi << ", " << p.se << " )" << endl; }
inline void pp64(p64 p) { cout << "( " << p.fi << ", " << p.se << " )" << endl; }
inline void ptri(tri t) { cout << "( " << t.fi << ", " << t.tse << ", " << t.th << " )" << endl; }
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

int a,b,ans,hi,lo,diff,p,tf;

int f(int p) {
	int ff = 0;
	ff += max(0,(p-4979900)/7), p = min(p,4979900);
	ff += max(0,(p-29900)/5), p = min(p,29900);
	ff += max(0,(p-200)/3), p = min(p,200);
	ff += max(0,p/2);
	return ff;
}

int val(int x) {
	int p = 0;
	if(x > 1000000) p += 7*(x-1000000), x = 1000000;
	if(x > 10000) p += 5 * (x - 10000), x = 10000;
	if(x > 100) p += 3 * (x - 100), x = 100;
	if(x > 0) p += 2 * x;
	return p;
}

int main(void) {
	fastio(0);
	while(cin >> a >> b && (a || b)) {
		tf = f(a);
		hi = f(a), lo = 0;
		while(lo<=hi) {
			ans = (hi+lo)/2, p = val(tf - ans), diff = abs(p-val(ans));
			if(diff<b) {
				hi = ans - 1;
			} else if(diff>b) {
				lo = ans + 1;
			} else {
				cout << val(ans) << endl;
				break;
			}
		}
	}
	return 0;
}
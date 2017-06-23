// Li Hong Sheng Gabriel's Competitive Programming Template

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
#define v64 vector<ll>
#define v32 vector<int>
#define vp64 vector<p64>
#define vp32 vector<p32>
#define vprint(a,sz) repn(k,sz) cout << setw(3) << right << a[k] << " "; cout << endl
#define mprint(a,rn,cn) repn(i,rn) { vprint(a[i],cn); cout << endl; }
#define INF32 INT_MAX
#define INF64 LLONG_MAX
#define pq priority_queue
#define minheap pq<int,v32,greater<int>>
#define maxheap pq<int>
#define gcd __gcd

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AVL:
// set functions, rank and select:
//cout<<*X.find_by_order(>=1)<<endl;
//cout<<X.order_of_key(>=1)<<endl;

inline void setscale(int x) { cout.precision(x); cout << fixed; }
int lcm(int x,int y) { return (x*y)/gcd(x,y); }
inline void fastio() { ios_base::sync_with_stdio(false); cin.tie(0); }
inline void pp32(p32 p) { cout << "( " << p.fi << ", " << p.se << " )" << endl; }
inline void pp64(p64 p) { cout << "( " << p.fi << ", " << p.se << " )" << endl; }
inline void ptri(tri t) { cout << "( " << t.fi << ", " << t.tse << ", " << t.th << " )" << endl; }
double dist(pdd x,pdd y) { return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)); }
//int find(int x) { return (par[x]==x) ? x : par[x]=find(par[x]);}

// End of Template
//#define debug

int n, ds[1010], ns[1010], l;
ll ans;

int main(void) {
	#ifdef debug
		freopen("in","r",stdin);
	#else
		fastio();
	#endif
	cin >> n;
	repn(i,n) {
		cin >> ds[i];
	}
	repn(i,n) {
		cin >> ns[i];
	}
	cin >> l;
	sort(ds,ds+n);
	sort(ns,ns+n,greater<int>());
	repn(i,n) {
		ans += 100*max(abs(ds[i]+ns[i])-l,0);
	}
	cout << ans << endl;
	return 0;
}
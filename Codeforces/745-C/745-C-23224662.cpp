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
#define minhp pq<int,v32,dsc<int>>
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
inline void fastio(int debug) {
	if(debug) {
		cout << "DEBUGGING MODE..." << endl;
		freopen("in","r",stdin);
	} else {
		ios_base::sync_with_stdio(false), cin.tie(0);
	}
}

// End of Template

int n, m, k, a, b;
int ans;
int par[1005];
int esz[1005];
int gov[1005];
int total,tmp;
v32 sp,nsp;

int find(int x) { return (par[x]==x) ? x : par[x]=find(par[x]);}

int all(int n) { return (n*(n-1))/2; }

int main(void) {
	fastio(0);
	cin >> n >> m >> k;
	repsn(i,1,n+1) par[i] = i, esz[i] = 1;
	repn(i,k) {
		cin >> a;
		gov[a] = 1;
	}
	repn(i,m) {
		cin >> a >> b;
		if(find(a)!= find(b)) {
			if(gov[find(a)] || gov[find(b)]) gov[find(b)] = 1;
			esz[find(b)] += esz[find(a)];
			par[find(a)] = find(b);
		}
	}
	//vprint(par,n+1);
	//vprint(esz,n+1);
	repsn(i,1,n+1) {
		if(par[i] == i) {
			if(gov[i]) {
				sp.pb(i);
			} else {
				nsp.pb(i);
				total += esz[i];
			}
			ans += all(esz[i]);
		}
	}
	//cout << "ans " << ans << endl;
	
	//cout << "total: " << total << endl;

	//vprint(nsp,nsp.sz);
	//vprint(sp,sp.sz);
	
	repn(i,nsp.sz) {
		repsn(j,i+1,nsp.sz) {
			//cout << "i: " << i << " " << "j1: " << j << endl;
			ans += esz[nsp[i]] * esz[nsp[j]];
		}
	}

	repn(i,sp.sz) {
		tmp = max(tmp, total * esz[sp[i]]);
	}

	//vprint(val,n+1);
	cout << ans - m + tmp << endl;
	return 0;
}
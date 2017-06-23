// Li Hong Sheng Gabriel's Competitive Programming Template v2017.1

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
#define valid(r,c,rn,cn) (r >= 0 && c >= 0 && r < rn && c < cn)
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
#define dmprint(a,s) repn(i,s) { cout << i << ": "; repn(j,a[i].sz) { cout << a[i][j] << " "; } cout << endl; }
#define INF32 INT_MAX
#define INF64 LLONG_MAX
#define dsc greater
#define pq priority_queue
#define minhp pq<int,v32,dsc<int>>
#define maxhp pq<int>
#define um unordered_map

// Uncomment the include files, namespace and type to use
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AVL:
// set functions, rank and select:
//select: cout<<*X.find_by_order(>=1)<<endl;
//rank: cout<<X.order_of_key(>=1)<<endl;

inline void scale(int x) { cout.precision(x); cout << fixed; }
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

ll dp[2001][10001];
vp32 s1,s2,ss2;
int vis[10001];
int N,X,Y,a,b,ans,tmp;
ll mon;

int main(void) {
	fastio(0);
	cin >> N >> X >> Y;
	repn(i,N) { // Loops from 0 to N-1 (inclusive)
		cin >> a >> b;
		s1.pb(mp(a,i));
		s2.pb(mp(b,i));
		ss2.pb(mp(b,i)); // sorted version of market 2's list
	}
	sort(s1.begin(),s1.end());
	sort(ss2.begin(),ss2.end()); // sorted version of market 2's list
	repsn(i,1,N+1) { // Loops from 1 to N (inclusive)
		mon = Y, tmp = 0;
		fill_n(vis,N+1,0);
		// DP to minimize spending in market 2
		repn(j,X+1) { // Loops from 0 to X (inclusive)
			if(j >= s1[i-1].fi) {
				dp[i][j] = min(s2[s1[i-1].se].fi+dp[i-1][j],dp[i-1][j-s1[i-1].fi]);
			} else {
				dp[i][j] = s2[s1[i-1].se].fi + dp[i-1][j];
			}
		}
		repsn(j,1,i+1) { // Loops from 1 to i (inclusive)
			vis[s1[j-1].se] = 1; // "blacklist" all purchased items
		}
		// If everything from market 2 is too expensive, buy only from market 1
		mon -= dp[i][X], tmp = i;
		//cout << "tmp is: " << tmp << endl;
		// greedy strategy using the leftover money in market 2
		if(mon >= 0) {
			//cout << "Here" << endl;
			repsn(j,1,N+1) { // Loops from 1 to N (inclusive)
				// Buy only the items that have not been bought, if there is enough money
				if(!vis[ss2[j-1].se] && mon >= ss2[j-1].fi) {
					mon -= ss2[j-1].fi;
					tmp++;
				}
			}
		} else {
			//cout << "else" << endl;
			mon = X, tmp = 0;
			repn(j,N) {
				if(mon < s1[j].fi) break;
				tmp++, mon -= s1[j].fi;
			}
		}
		ans = max(ans,tmp);
	}
	cout << ans << "\n";
	return 0;
}
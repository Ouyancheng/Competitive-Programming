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

#define MAX_N 20
#define BITMASK 2097152

ll arr[MAX_N], dp[BITMASK];
int n;
ll rsum;

int togglebit(int i,int mask) {
    return mask ^ (1 << i);
}

bool isset(int i,int mask) {
    return mask & (1 << i);
}

ll solve(int mask,ll rsum) {
    if(!mask) return dp[mask] = 0;
    else if(dp[mask] != -1) return dp[mask];
    for(int i = 0; i < n; i++) {
        if(!isset(n-1-i,mask)) continue;
        dp[mask] = max(dp[mask],solve(togglebit(n-1-i,mask),rsum-arr[i]) + (rsum-arr[i])%arr[i]);
    }
    return dp[mask];
}

int main(void) {
    fastio(0);
    cin >> n;
    repn(i,(1<<n)) dp[i] = -1;
    repn(i,n) {
        cin >> arr[i];
        rsum += arr[i];
    }
    cout << solve((1<<n)-1,rsum) << breakl;
    return 0;
}

// Li Hong Sheng Gabriel's Competitive Programming Template v2017.4
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>

//using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define sz size()
#define pp pop()
#define P32 pair<int,int>
#define P64 pair<ll,ll>
#define PDD pair<double,double>
#define fi first
#define se second
#define REPN(i,e) for(int i = 0; i < e; i++)
#define REPSN(i,s,e) for(int i = s; i < e; i++)
#define RREPN(i,s) for(int i = s; i >= 0; i--)
#define RREPSN(i,s,e) for(int i = s; i >= e; i--)
#define V64 vector<ll>
#define V32 vector<int>
#define VP64 vector<P64>
#define VP32 vector<P32>
#define APRINT(a,s) if(DRAFT) REPN(k,s) cout << setw(3) << right << a[k] << " "; cout << endl
#define MPRINT(aa,rn,cn) if(DRAFT) REPN(i,rn) { APRINT(aa[i],cn); cout << endl; }
#define VPRINT(a) if(DRAFT) REPN(k,a.sz) cout << setw(3) << right << a[k] << " "; cout << endl
#define VVPRINT(a) if(DRAFT) REPN(i,a.sz) { cout << i << ": "; REPN(j,a[i].sz) { cout << a[i][j] << " "; } cout << endl; }
#define VALUE(a) if(DRAFT) { cout << "DEBUG: The value of " << #a << " is " << a << endl; }
#define VALUEP(p) { if(DRAFT) cout << "( " << p.fi << ", " << p.se << " )" << endl; }
#define INF32 INT_MAX
#define INF64 LLONG_MAX
#define ALL(a) a.begin(),a.end()
#define UM unordered_map
#define US unordered_set
#define breakl "\n"

// Uncomment the include files, namespace and type to use
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AVL:
// set functions, rank and select:
//select: cout<<*X.find_by_order(>=1)<<endl;
//rank: cout<<X.order_of_key(>=1)<<endl;

inline void scale(int x) { cout.precision(x); cout << fixed; }
double dist(PDD x,PDD y) { return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)); }
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

bool DRAFT = 1;

int n, arr[100000],arr2[100000];
int lo = INF32, hi = -INF32;

int main(void) {
	fastio(0);
	cin >> n;
	REPN(i,n) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	REPSN(i,1,n) {
		if(arr2[i-1] > arr2[i]) {
			lo = min(lo,i-1);
			hi = max(hi,i);
		} else if(lo != INF32) {
			break;
		}
	}
	if(lo != INF32) {
		reverse(arr2+lo,arr2+hi+1);
		REPSN(i,lo,hi+1) {
			arr[i] = arr2[i];
		}
		if(is_sorted(arr,arr+n)) {
			cout << "yes" << breakl;
			cout << ++lo << " " << ++hi << breakl;
		} else {
			cout << "no" << breakl;
		}
	} else {
		cout << "yes" << breakl;
		cout << "1 1" << breakl;
	}
	return 0;
}
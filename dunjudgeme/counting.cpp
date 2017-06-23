#include<iostream>
#include<unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define ll long long
#define um unordered_map 
#define LIM 400001

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  ll,
  null_type,
  less<ll>,
  rb_tree_tag,
  tree_order_statistics_node_update>
AVL;

ll N, arr[LIM];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,c,d,Q;
	cin >> N >> Q;
	um<ll,AVL> m;

	for(ll i = 1; i <= N; i++) {
		cin >> arr[i];
		if(m.find(arr[i])==m.end()) m.insert(mp(arr[i],AVL()));
		m[arr[i]].insert(i);
	}
	for(ll i = 1; i <= Q; i++) {
		cin >> c;
		if(c==1) {
			cin >> a >> b >> d;
			if(m.find(d)!=m.end()) {
			    ll lo,hi;
			    auto p = m[d].lower_bound(a);
			    lo = (p==m[d].end()) ? -1 : *p;
			    if(lo==-1) {
			        cout << "0" << "\n";
			    } else {
			        lo = m[d].order_of_key(lo)+1;
			        if(m[d].find(b)!=m[d].end()) {
			            cout << m[d].order_of_key(b) + 1 - 
			            lo + 1 << "\n";
			        } else {
			            p = m[d].lower_bound(b);
			            hi = (p==m[d].end()) ? -1 : *p;
			            if(hi == -1) {
    			            cout << m[d].size() - lo + 1 << "\n";
			            } else {
    			            cout << m[d].order_of_key(hi) - lo + 1 << "\n";			                
			            }
			        }
			    }
			} else {
				cout << "0" << "\n";
			}
		} else {
			cin >> a >> b;
			m[arr[a]].erase(a);
			if(m.find(b)==m.end()) m.insert(mp(b,AVL()));
			m[b].insert(a);
			arr[a] = b;
		}
	}

}
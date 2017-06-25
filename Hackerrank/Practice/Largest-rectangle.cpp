#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define mp make_pair
#define ll long long
#define pb push_back
#define fi first
#define se second

int n,a;
int lo;
vector<int> rect;

// Pre-condition: n: number of rectangles
// rect: vector containing the height of the rectangles
// the macro ll long long must be defined
// Post-condition: The maximum contiguous area that can be formed
// by the given rectangles
ll maxhistogram(int n,vector<int> &rect) {
	vector< pair<int,int> > v;
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		int a = rect[i];
		if(!v.size() || v.back().fi < a) {
			v.pb(mp(a,i));
		} else {
			int lo = i, len = 0;
			while(v.size() > 0 && v.back().fi >= a) {
				ans = max(ans,(ll) (v.back().fi) * (i - v.back().se));
				lo = v.back().se;
				v.pop_back();
			}
			v.pb(mp(a,lo));
		}
	}
	while(v.size()) {
		ans = max(ans,(ll) v.back().fi * (n - v.back().se));
		v.pop_back();
	}
	return ans;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		rect.pb(a);
	}
	cout << maxhistogram(n,rect) << "\n";
	return 0;
}
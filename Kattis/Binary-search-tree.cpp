#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;
set<int> o;
int a, n, lvl[maxn];
ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		auto g = o.upper_bound(a);
		auto s = o.lower_bound(a);
		if(s != o.begin()) {
			s--;
		} else {
			s = o.end();
		}
		if(g == o.end() && s != o.end()) {
			lvl[a] = lvl[*s] + 1;
		} else if(g != o.end() && s == o.end()) {
			lvl[a] = lvl[*g] + 1;
		} else if(g != o.end() && s != o.end()) {
			lvl[a] = (lvl[*g] < lvl[*s]) ? lvl[*s] + 1 : lvl[*g] + 1;
		}
		o.insert(a);
		ans += lvl[a];
		cout << ans << "\n";
	}
	return 0;
}

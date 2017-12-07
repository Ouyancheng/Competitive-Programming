#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<cassert>

using namespace std;

int n, a, b, ans;
vector< pair<int,int> > v;
vector< pair<int,int> > s;

int diff(const pair<int,int> &p1, const pair<int,int> &p2) {
	if(p1.first == p2.first) {
		return abs(p2.second - p1.second);
	} else {
		assert(p1.first < p2.first);
		int d = 60 - p1.second;
		d += 60 * (p2.first - p1.first - 1);
		d += p2.second;
		return d;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	for(int i = 0; i < (int) v.size(); i++) {
		while((int) s.size() > 0 && diff(s.back(),v[i]) >= 1) {
			s.pop_back();
		}
		s.push_back(v[i]);
		ans = max(ans,(int)s.size());
	}
	cout << ans << "\n";
	return 0;
}

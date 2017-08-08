#include<iostream>
#include<algorithm>

using namespace std;

int t,r,h;
double ans,hou[100002];

bool can(double rad) {
	int use = 0; double cur = -1e6-3;
	for(int i = 0; i < h; i++) {
		if(hou[i]-(cur+rad)>1e-10) {
			cur = hou[i]+rad;
			if(++use > r) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(1);
	cout << fixed;

	cin >> t;
	while(t--) {
		cin >> r >> h;
		for(int i = 0; i < h; i++)
			cin >> hou[i];
		sort(hou,hou+h);

		double lo = 0, hi = 1e6+2;

		for(int i = 0; i < 100; i++) {
			double mid = (lo+hi)/2;
			if(can(mid)) {
				ans = mid;
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
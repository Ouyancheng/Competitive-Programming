#include<iostream>

using namespace std;

int n,m;
int a[1003];

bool can(int cap) {
	int c = m, cur = 0;
	while(cur < n && c > 0) {
		int t = cap;
		if(a[cur] > cap) break;
		while(cur < n && (t -= a[cur]) >= 0)
			cur++;
		c--;
	}
	return cur == n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m) {
		for(int i = 0; i < n; i++)
			cin >> a[i];

		int lo = 1, hi = 1000000000;

		for(int i = 0; i < 40; i++) {
			int mid = (lo+hi)>>1;
			if(can(mid)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << (can(lo) ? lo : hi) << "\n";
	}
	return 0;
}
#include<iostream>

using namespace std;

typedef long long ll;

ll ap(int i) {
	return (1LL * i * (i+1))/2;
}

ll solve(ll n) {
	ll lo = 0, hi = 1e9;
	while(lo < hi) {
		ll mid = lo + hi >> 1;
		ll res = ap(mid);

		if(res > n) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return hi - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; ll n;
	cin >> t;

	while(t--) {
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;

int n, m;
ll a[maxn];

int bs(int i, int j, ll k) {
	int lo = i, hi = j, ans = -1;

	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(a[mid] - a[i-1] <= k) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}

bool can(ll k) {
	int lo = 1, cur = 0;
	while(cur < m - 1 && lo <= n) {
		int ti = bs(lo, n-(m-cur)+1, k);
		if(ti == -1) {
			return 0;
		}
		lo = ti + 1;
		cur++;
	}
	return cur == m - 1 && a[n] - a[lo-1] <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1]; 
	}

	ll lo = 1, hi = a[n], ans = 0;

	while(lo <= hi) {
		ll mid = lo + hi >> 1;
		if(can(mid)) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}

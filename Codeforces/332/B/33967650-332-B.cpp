#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

typedef long long ll;

int n, k;
ll a[maxn], dp1[maxn], dp2[maxn], dp11[maxn], dp21[maxn], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	ll cur = 0; int curi = 0, l, r;

	for(int i = k; i <= n; i++) {
		if(a[i] - a[i-k] > cur) {
			curi = i - k + 1;
		}
		cur = max(cur, a[i] - a[i-k]);
		dp1[i] = cur;
		dp11[i] = curi;
	}

	cur = curi = 0;

	for(int i = n-k; i; i--) {
		if(a[i+k] - a[i] >= cur) {
			curi = i + 1;
		}
		cur = max(cur, a[i+k] - a[i]);
		dp2[i] = cur;
		dp21[i] = curi;
	}

	for(int i = 1; i <= n; i++) {
		if(dp1[i] + dp2[i] > ans) {
			l = dp11[i], r = dp21[i];
		}
		ans = max(ans, dp1[i] + dp2[i]);
	}
	cout << l << " " << r << "\n";
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll oo = 1e18;
const int maxn = 2e6;

int n, ai, bi, asz, bsz, a[10], b[10], pr[18];
ll ap[maxn], bp[maxn], k;

void gen(int p[], int n, ll f[], int &sz, int cur = 0, ll mul = 1) {
	if(cur < n) {
		ll pw = 1;
		for(int i = 0; i <= 60; i++) {
			pw = (i ? pw * p[cur] : 1); ll a = pw * mul;
			if(oo/pw >= mul) {
				gen(p, n, f, sz, cur + 1, a);
				if(cur == n - 1) {
					f[sz++] = a;
				}
			} else {
				break;
			}
		}
	}
}

pair<ll, ll> val(ll k) {
	int ca = 0, cb = bsz - 1;
	ll ans = 0, ret = 0;

	while(ca < asz && cb >= 0) {
		if(k/bp[cb] >= ap[ca]) {
			ans += 1LL * (cb + 1);
			if(ans > k) {
				break;
			}
			ret = max(ret, bp[cb] * ap[ca]);
			ca++;
		} else {
			cb--;
		}
	}
	return make_pair(ans, ret);
}

ll work(ll k) {
	ll lo = 1, hi = oo;
	while(lo <= hi) {
		ll mid = lo + hi >> 1; pair<ll,ll> v = val(mid);
		if(v.first == k) {
			return v.second;
		} else if(v.first < k) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	assert(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> pr[i];
	}

	random_shuffle(pr, pr + n);

	for(int i = 0; i < n; i++) {
		if(i & 1) {
			a[ai++] = pr[i];
		} else {
			b[bi++] = pr[i];
		}
	}
	
	cin >> k;

	gen(a, ai, ap, asz); gen(b, bi, bp, bsz);
	if(asz == 0) {
		ap[asz++] = 1;
	}
	sort(ap, ap + asz); sort(bp, bp + bsz);

	cout << work(k) << "\n";
	return 0;
}

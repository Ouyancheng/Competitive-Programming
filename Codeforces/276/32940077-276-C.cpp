#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;
int n, a[maxn], b[maxn], q, x, y;
ll f[maxn], ans;

void update(int a,int b,int v) {
	b++;
	while(a <= n) {
		f[a] += v;
		a += a & -a;
	}
	while(b <= n) {
		f[b] -= v;
		b += b & -b;
	}
}

ll query(int a) {
	ll ans = 0;
	while(a) {
		ans += f[a];
		a -= a & -a;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= q; i++) {
		cin >> x >> y;
		update(x,y,1);
	}
	for(int i = 1; i <= n; i++) {
		b[i] = query(i);
	}
	sort(b,b+n+1);
	sort(a,a+n+1);
	for(int i = n; i >= 1 && b[i]; i--) {
		ans += 1LL * a[i] * b[i];
	}
	cout << ans << "\n";
	return 0;
}
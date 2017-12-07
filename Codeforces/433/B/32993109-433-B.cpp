#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
const int maxn = 100005;
int n, q, x, y, z;
ll b[maxn], a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i = 1; i <= n; i++) {
		a[i] += a[i-1];
	}
	sort(b+1,b+n+1);
	for(int i = 1; i <= n; i++) {
		b[i] += b[i-1];
	}
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> x >> y >> z;
		if(x == 1) {
			cout << a[z] - a[y-1] << "\n";
		} else {
			cout << b[z] - b[y-1] << "\n";
		}
	}

	return 0;
}

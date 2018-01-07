#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

int r, g, b;
ll ans;

int main() {
	cin >> r >> g >> b;
	int a = min(r-3, min(g-3, b-3));
	a = max(a, 0);

	r -= a, g -= a, b -= a;

	for(int i = 0; i <= min(r, min(g, b)); i++) {
		ans = max(ans, 0LL + a + i + (r-i)/3 + (g-i)/3 + (b-i)/3);
	}
	cout << ans << "\n";

	return 0;
}

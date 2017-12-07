#include<iostream>

using namespace std;

int n, a, b, c;

int val(int x, int y) {
	int z = (n - a * x - b * y);
	if(z % c) return 0;
	z /= c;
	if(z < 0) return 0;
	return x + y + z;
}

int main() {
	cin >> n >> a >> b >> c;
	int ans = 0;

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			ans = max(ans,val(i,j));
		}
	}
	cout << ans << "\n";
}
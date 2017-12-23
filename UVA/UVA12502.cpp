#include<iostream>
#include<algorithm>

using namespace std;

int x, y, z;
int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout.precision(0);
	cout << fixed;

	cin >> t;

	while(t--) {
		cin >> x >> y >> z;
		int k = (x + x - y) * z;
		int val = k/(x+y);
		val = max(val, 0);
		cout << val << "\n";
	}
}

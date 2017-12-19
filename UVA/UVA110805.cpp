#include<iostream>

using namespace std;

int t, n, k, p;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n >> k >> p;
		p %= n;
		k--;
		cout << "Case " << i << ": ";
		cout << (p + k) % n + 1 << "\n";
	}
	return 0;
}

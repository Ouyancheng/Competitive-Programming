#include<iostream>

using namespace std;

int t, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> a;
		int r = a % 4, ans;
		if(r == 0) {
			ans = a / 4;
		} else if(r == 1) {
			ans = a / 4 - 2 + 1;
		} else if(r == 2) {
			ans = a / 4 - 1 + 1;
		} else {
			ans = a / 4 - 3;
			if(ans >= 0) {
				ans = ans + 2;
			}
		}
		cout << (ans > 0 ? ans : -1) << "\n";
	}
	return 0;
}
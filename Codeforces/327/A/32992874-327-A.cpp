#include<iostream>

using namespace std;

int n, ans;
bool a[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int ones = 0;
			for(int k = i; k <= j; k++) {
				a[k] = !a[k];
			}
			for(int k = 0; k < n; k++) {
				ones += a[k];
			}
			for(int k = i; k <= j; k++) {
				a[k] = !a[k];
			}
			ans = max(ans,ones);
		}
	}
	cout << ans << "\n";
	return 0;
}

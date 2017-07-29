#include<iostream>
#include<algorithm>

using namespace std;

int ans,t,a,n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int x = 1; x <= t; x++) {
		ans = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a;
			ans = max(ans,a);
		}
		cout << "Case " << x << ": " << ans << "\n";
	}
	return 0;
}
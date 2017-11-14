#include<iostream>

using namespace std;

int n, a[25], t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n) {
		cin >> t;
		int ans = 0, mask = 0;
		for(int i = 0; i < t; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < (1 << t); i++) {
			//cout << "the value of i is " << i << endl;
			int minutes = 0;
			for(int j = 0; (1<<j) <= i; j++) {
				if(i & (1<<j)) {
					minutes += a[j];
				}
				if(minutes > n) {
					break;
				}
			}
			//cout << "value of minutes is " << minutes << endl;
			if(minutes <= n && n - minutes < n - ans) {
				mask = i;
				ans = minutes;
			}
		}
		for(int i = 0; i < t; i++) {
			if(mask & (1 << i)) {
				cout << a[i] << " ";
			}
		}
		cout << "sum:" << ans << "\n";
	}
	
	return 0;
}

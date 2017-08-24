#include<bits/stdc++.h>

using namespace std;

int t,a,b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> a >> b;
		if(b % a != 0) {
			cout << -1;
		} else {
			cout << a << " " << b;
		}
		cout << "\n";
	}
	return 0;
}
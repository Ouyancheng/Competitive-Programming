#include<bits/stdc++.h>

using namespace std;

int t, n, d;
string s;

int p(int b) {
	long long ans = 1;
	for(int i = b; i <= n && ans <= d; i++) {
		ans *= i;
	}
	return (ans > d) ? 0 : d/ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		string ans = "";

		cin >> s >> d;
		d--;

		n = (int) s.length();

		for(int i = 0; i < n; i++) {
			int pos = p(i+2) % (i+1);
			ans = ans.substr(0, pos) + s[i] + ans.substr(pos);
		}
		cout << ans << "\n";
	}
	return 0;
}

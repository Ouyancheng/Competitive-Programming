#include<iostream>

using namespace std;

int n,k,t;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int c = 1, ans = 0; c <= t; c++, ans = 0) {
		cin >> n >> k >> s;
		for(int i = 0; i < n; i++) {
			for(int j = max(0,i - k); j < i; j++) {
				if(s[i] == s[j]) {
					ans++;
					break;
				}
			}
		}
		cout << "Case " << c << ": " << ans << "\n";
	}
	return 0;
}
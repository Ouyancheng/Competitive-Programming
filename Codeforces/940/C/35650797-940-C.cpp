#include<bits/stdc++.h>

using namespace std;

int n, k, pos, pos2;
string s, s2, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> s;
	s2 = s;
	sort(s2.begin(), s2.end());
	if(k <= n) {
		for(int i = min(k, n) - 1; i >= 0; i--) {
			if(s[i] != s2[n-1]) {
				pos = i;
				break;
			}
		}
		for(int i = 0; i < n; i++) {
			if(s2[i] > s[pos]) {
				pos2 = i;
				break;
			}
		}
		ans = s.substr(0, pos) + s2[pos2];
		for(int i = pos + 1; i < k; i++) {
			ans += s2[0];
		}	
	} else {
		ans = s;
		for(int i = n; i < k; i++) {
			ans += s2[0];
		}
	}
	cout << ans << "\n";
}
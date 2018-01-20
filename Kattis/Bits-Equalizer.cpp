#include<bits/stdc++.h>

using namespace std;

int t;
string s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int i = 1, ans = 0, oi = 0, zi = 0, qi = 0, o1 = 0, o2 = 0; i <= t; i++, ans = o1 = o2 = oi = zi = qi= 0) {
		cin >> s1 >> s2;
		for(int j = 0; j < (int) s1.length(); j++) {
			if(s1[j] == '1') {
				o1++;
			}
			if(s2[j] == '1') {
				o2++;
			}
			if(s1[j] == '1' && s2[j] == '0') {
				oi++;
			} else if(s1[j] == '0' && s2[j] == '1') {
				zi++;
			} else if(s1[j] == '?') {
				qi++;
			}
		}
		if(o1 > o2) {
			ans = -1;
		} else {
			assert(oi <= qi + zi);
			ans += oi;
			zi = max(0, zi - oi);
			ans += zi + qi;
		}
		cout << "Case " << i << ": " << ans << "\n";
    }
    return 0;
}
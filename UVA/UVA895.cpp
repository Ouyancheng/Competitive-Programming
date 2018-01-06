#include<bits/stdc++.h>

using namespace std;

string s;
int si, dat[28], dats[28];
string a[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> s) {
		if(s == "#") {
			break;
		}
		a[si++] = s;
	}
	cin >> ws;
	while(getline(cin, s)) {
		int ans = 0;
		memset(dat, 0, sizeof dat);

		if(s == "#") {
			break;
		}
		for(int i = 0; i < (int) s.length(); i++) {
			if(s[i] >= 'a' && s[i] <= 'z') {
				dat[s[i]-'a']++;
			}
		}
		for(int i = 0; i < si; i++) {
			memset(dats, 0, sizeof dats);
			for(char c : a[i]) {
				dats[c-'a']++;
			}

			bool can = 1;
			for(int j = 0; j < 26; j++) {
				if(dat[j] < dats[j]) {
					can = 0;
					break;
				}
			}
			ans += can;
		}
		cout << ans << "\n";
	}
	return 0;
}

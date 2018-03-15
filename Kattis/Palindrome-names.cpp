#include<bits/stdc++.h>

using namespace std;

string ans, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < (int) s.length(); i++) ans += 'z';
	for(int i = 0; i < (int) s.length(); i++) {
		for(int j = i+1; j < (int) s.length()-1; j++) {
			string s1 = s.substr(0, i+1);
			string s2 = s.substr(i+1, j-(i+1)+1);
			string s3 = s.substr(j+1);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			ans = min(ans, s1 + s2 + s3);
		}
	}
	cout << ans << endl;
}

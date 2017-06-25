#include<bits/stdc++.h>

using namespace std;

int n;
string s;
int c[26];

int main() {
	cin >> n >> s;
	for(int i = 0; i < s.length(); i++) {
		c[s[i]-'a']++;
	}
	for(int i = 0; i < 26; i++) {
		if(c[i] % n != 0) {
		    cout << -1 << endl;
		    return 0;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int i = 0; i  < 26; i++) {
			if(c[i] > 0) {
				for(int k = 0; k < c[i]/n; k++) cout << (char) (i + 'a');
			}
		}
	}
	cout << endl;
	return 0;
}
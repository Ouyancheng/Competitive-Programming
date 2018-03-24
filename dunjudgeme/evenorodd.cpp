#include<bits/stdc++.h>

using namespace std;

string s;
int t;

int main() {
	cin >> t;
	while(t--) {
		cin >> s;
		int rem = 0;
		for(int i = 0; i < (int) s.length(); i++) {
			rem = (rem * 10 + (s[i] - '0')) % 2;
		}
		cout << (rem ? "odd" : "even") << endl;
	}
	return 0;
}
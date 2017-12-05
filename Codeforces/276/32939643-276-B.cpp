#include<iostream>
#include<string>

using namespace std;

string s;
int t[26], odd, n;

int main() {
	cin >> s;
	n = (int) s.length();
	for(int i = 0; i < n; i++) {
		t[s[i]-'a']++;
	}
	for(int i = 0; i < n; i++) {
		if(t[s[i]-'a'] & 1) {
			odd++;
		}
	}
	if(odd) {
		if(odd & 1) {
			cout << "First";
		} else {
			cout << "Second";
		}	
	} else {
		cout << "First";
	}
	return 0;
}
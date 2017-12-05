#include<iostream>
#include<string>
using namespace std;

int t1[200], t2[200];
string s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s1);
	getline(cin,s2);
	for(char c : s1) {
		if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			t1[c-'A']++;
		}
	}
	for(char c : s2) {
		if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			t2[c-'A']++;
		}
	}
	for(int i = 0; i < 199; i++) {
		if(t2[i] > t1[i]) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

#include<iostream>

using namespace std;

char fmap[26];
char rmap[26];
string s1,s2;

bool isUpper(char c) {
	return c >= 'A' && c <= 'Z';
}

bool isLower(char c) {
	return c >= 'a' && c <= 'z';
}

char toLower(char c) {
	return c + 'a' - 'A';
}

char toUpper(char c) {
	return c - 'a' + 'A';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2;
	int a1 = (int) s1.length();
	for(int i = 0; i < a1; i++) {
		fmap[s1[i]-'a'] = s2[i];
		rmap[s2[i]-'a'] = s1[i];
	}
	cin >> s1;
	a1 = (int) s1.length();
	for(int i = 0; i < a1; i++) {
		if(!isUpper(s1[i]) && !isLower(s1[i])) {
			cout << s1[i];
		} else if(isUpper(s1[i])) {
			cout << toUpper(fmap[toLower(s1[i])-'a']);
		} else {
			cout << fmap[s1[i]-'a'];
		}
	}
	cout << "\n";
	return 0;
}
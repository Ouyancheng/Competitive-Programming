#include<iostream>
#include<string>

using namespace std;

string s1, s2;

int main() {
	cin >> s1 >> s2;
	int n = (int) s1.length();
	int m = (int) s2.length();
	if(n != m) {
		cout << "NO";
	} else {
		bool has1 = 0;
		bool has2 = 0;

		for(int i = 0; i < n; i++) {
			if(s1[i] == '1') {
				has1 = 1;
				break;
			}
		}
		for(int i = 0; i < m; i++) {
			if(s2[i] == '1') {
				has2 = 1;
				break;
			}
		}
		if(s1 == s2) {
			cout << "YES";
		} else if(n == 1) {
			cout << "NO";
		} else if(!has2) {
			cout << "NO";
		} else {
			cout << (has1 ? "YES" : "NO");
		}
	}
	cout << "\n";

	return 0;
}

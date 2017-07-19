#include<iostream>

using namespace std;

string s1,s2;

int main() {
	ios::sync_with_stdio(false);
	cin >> s1 >> s2;
	int t1 = (int) s1.length();
	int t2 = (int) s2.length();

	if(t1 > t2) {
		cout << t1;
	} else if(t2 > t1) {
		cout << t2;
	} else {
		for(int i = 0; i < t1; i++) {
			if(s1[i] != s2[i]) {
				cout << t1;
				goto done;
			}
		}
		cout << -1;
	}
	done: cout << "\n";
	return 0;
}
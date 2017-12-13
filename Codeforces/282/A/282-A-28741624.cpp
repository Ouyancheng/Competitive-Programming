#include<iostream>

using namespace std;

int n,x;
string s;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		if(s[0]=='+' || s[2]=='+') {
			x++;
		} else {
			x--;
		}
	}
	cout << x << "\n";
	return 0;
}
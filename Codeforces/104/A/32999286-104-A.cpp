#include<iostream>

using namespace std;

int n;

int main() {
	cin >> n;
	n -= 10;
	if(n == 10) {
		cout << 15;
	} else if(n == 11) {
		cout << 4;
	} else if(n >= 1 && n <= 9) {
		cout << 4;
	} else {
		cout << 0;
	}
	cout << "\n";
	return 0;
}

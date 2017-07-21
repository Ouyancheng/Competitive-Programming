#include<iostream>

using namespace std;

int a,b;

int main() {
	cin >> a >> b;
	if(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
		cout << "Possible";
	} else {
		cout << "Impossible";
	}
	cout << "\n";
	return 0;
}
#include<iostream>

using namespace std;

unsigned int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> a >> b) {
		cout << (a^b) << "\n";
	}
	return 0;
}

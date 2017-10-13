#include<iostream>

using namespace std;

int main() {
	long long l,r;
	cin >> l >> r;
	long long res = l ^ r, ret = 1;
	while(ret <= res) {
		ret <<= 1;
	}
	cout << --ret << "\n";
	return 0;
}

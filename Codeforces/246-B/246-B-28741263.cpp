#include<iostream>

using namespace std;

int n,sum,a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
	}
	if(sum % n) {
		cout << n-1 << "\n";
	} else {
		cout << n << "\n";
	}
	return 0;
}
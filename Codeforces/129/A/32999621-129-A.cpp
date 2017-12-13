#include<iostream>

using namespace std;

int n, a, even, odd, sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a & 1) {
			odd++;
		} else {
			even++;
		}
		sum += a;
	}
	if(sum & 1) {
		cout << odd;
	} else {
		cout << even;
	}
	cout << "\n";
}

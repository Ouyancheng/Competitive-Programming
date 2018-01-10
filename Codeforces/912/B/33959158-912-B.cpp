#include<iostream>

using namespace std;

typedef long long ll;

ll n, k;

int main() {
	cin >> n >> k;
	if(k == 1) {
		cout << n;
	} else {
		int i = 0;
		while((1LL << i) <= n) {
			i++;
		}
		cout << (1LL << i) - 1;
		cout << "\n";
	}
	return 0;
}
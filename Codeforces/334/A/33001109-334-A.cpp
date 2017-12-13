#include<iostream>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0, k = i; j < n; j++, k = (k+1) % n) {
			cout << j * n + k + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}

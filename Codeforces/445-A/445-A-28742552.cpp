#include<iostream>

using namespace std;

int n,m;
char c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> c;
			if(c == '.') {
				cout << (((i+j)&1) ? "B" : "W");
			} else {
				cout << c;
			}
		}
		cout << "\n";
	}
	return 0;
}
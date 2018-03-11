#include<bits/stdc++.h>

using namespace std;

string s;
int a[12], n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cout << "Lumberjacks:" << "\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 10; j++) {
			cin >> a[j];
		}
		if(is_sorted(a, a + 10)) {
			cout << "Ordered" << "\n";
		} else {
			reverse(a, a + 10);
			if(is_sorted(a, a + 10)) {
				cout << "Ordered" << "\n";
			} else {
				cout << "Unordered" << "\n";
			}
		}
	}
	return 0;
}

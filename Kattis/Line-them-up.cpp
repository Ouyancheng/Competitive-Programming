#include<bits/stdc++.h>

using namespace std;

const int maxn = 20;

int n;
string a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(is_sorted(a, a + n)) {
		cout << "INCREASING";
	} else {
		reverse(a, a + n);
		if(is_sorted(a, a + n)) {
			cout << "DECREASING";
		} else {
			cout << "NEITHER";
		}
	}
	cout << "\n";
	return 0;
}

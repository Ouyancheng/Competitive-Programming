#include <bits/stdc++.h>

using namespace std;

int t, n, x, a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
     x = n = 0;
     cin >> n;
	 for(int i = 0; i < n; i++) {
	     cin >> a;
	     x ^= a;
	 }
	 cout << x << "\n";
    }
	return 0;
}
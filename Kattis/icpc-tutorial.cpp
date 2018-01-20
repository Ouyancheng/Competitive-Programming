#include<bits/stdc++.h>

using namespace std;

int n, m, t;

bool go() {
	if(t == 1) {
		if(n == 1) {
			return 1;
		} else {
			long long fac = 1;
			int it = 0;
			for(int i = 1; i <= n && fac < m; i++, it++) {
				fac *= i;
			}
			return (it == n && fac <= m);
		}
	} else if(t == 2) {
		long long fac = 1;
		int it = 0;
		for(int i = 1; i <= n && fac < m; i++, it++) {
			fac <<= 1;
		}
		return (it == n && fac <= m);
	} else if(t >= 3 && t <= 5) {
		long long fac = 1;
		int it = 0;
		for(int i = 1; i <= 4 - (t - 3) && fac <= m; i++, it++) {
			fac *= n;
		}
		return (it == (4 - (t - 3)) && fac <= m);
	} else if(t == 6) {
		return m - n * log2(n) >= 1e-10;
	} else {
		return n <= m;
	}
}

int main() {
	cin >> m >> n >> t;
	if(go()) {
		cout << "AC";
	} else {
		cout << "TLE";
	}
	cout << "\n";
	return 0;
}
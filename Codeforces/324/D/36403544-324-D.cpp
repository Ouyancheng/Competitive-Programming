#include<bits/stdc++.h>

using namespace std;

int n;

bool f(int n) {
	for(int i = 2; i*i <= n; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

int main() {
	cin >> n;
	if(n == 3) {
		cout << 1 << "\n" << "3" << "\n";
	} else {
		int i;
		for(i = n-1; !f(i); i--);
		int d = n-i;
		if(f(d)) {
			cout << "2" << "\n" << i << " " << d << "\n";
		} else {
			int j, k;
			for(j = 2; j < min(d, 220); j++) {
				for(k = 2; k < min(d, 220); k++) {
					if(f(j) && f(k) && j+k == d) goto fin;
					else if(j+k > d) break;
				}
			}
			fin: cout << "3" << "\n" << i << " " << j << " " << k << "\n";
		}
	}
	return 0;
}
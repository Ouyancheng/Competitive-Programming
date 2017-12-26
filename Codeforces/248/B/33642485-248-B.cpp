#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n;
char c[maxn];

bool can(char s[], int d) {
	int rem = 0;
	for(int i = 0; i < n; i++) {
		rem *= 10;
		rem = (rem + (s[i]-'0')) % d;
	}
	return !rem;
}

string gen() {
	c[0] = '1';
	for(int i = 1; i < n; i++) {
		c[i] = '0';
	}
	for(int i = 0; i <= 2; i++) {
		for(int j = 0; j <= 9; j++) {
			c[n-2] = j+'0', c[n-3] = i+'0';
			if(can(c, 3) && can(c, 7)) {
				return string(c);
			}
		}
	}
}

int main() {
	cin >> n;
	if(n < 3) {
		cout << -1;
	} else if(n == 3) {
		cout << 210;
	} else {
		cout << gen();
	}
	cout << "\n";
	return 0;
}

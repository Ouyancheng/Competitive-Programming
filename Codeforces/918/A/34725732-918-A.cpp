#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;
int f[maxn], n;
unordered_set<int> S;

void calc() {
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i < maxn; i++) {
		f[i] = f[i-1] + f[i-2];
		S.insert(f[i]);
	}
}

int main() {
	cin >> n;
	calc();
	for(int i = 1; i <= n; i++) {
		if(S.find(i) != S.end()) {
			cout << 'O';
		} else {
			cout << 'o';
		}
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 5;

int a[MAX_N], b[MAX_N], c[MAX_N], n;

bool cmp(int i,int j) {
	return b[i] < b[j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a+n,greater<int>());
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		c[i] = i;
	}
	sort(c,c+n,cmp);
	for(int i = 0; i < n; i++) {
		b[c[i]] = a[i];
	}
	for(int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << "\n";
	return 0;
}

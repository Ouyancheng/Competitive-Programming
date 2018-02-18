#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e2 + 5;
int n, c;
string a[maxn];

bool cmp(const string &s1, const string &s2) {
	if(s1.length() > 1 && s2.length() > 1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		return 0;
	}
	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		if(c++ > 0) {
			cout << "\n";
		}
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		stable_sort(a, a + n, cmp);
		for(int i = 0; i < n; i++) {
			cout << a[i] << "\n";
		}
	}
}

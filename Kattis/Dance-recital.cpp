#include<bits/stdc++.h>

using namespace std;

const int maxn = 12;
int n, M[maxn], C[maxn];
string s;

int go() {
	int ans = (int) 1e9;
	vector<int> v(n);
	iota(v.begin(), v.end(), 0);
	do {
		int tmp = 0;
		for(int i = 1; i < n; i++) {
			tmp += __builtin_popcount(M[v[i]] & M[v[i-1]]);
		}
		ans = min(ans, tmp);
	} while(next_permutation(v.begin(), v.end()));
	return ans;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(char c : s) {
			int v = c - 'A';
			M[i] |= (1<<v);
		}
	}
	cout << go() << "\n";
	return 0;
}

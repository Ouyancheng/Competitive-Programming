#include<bits/stdc++.h>

using namespace std;

unordered_map<string, string> M;
int n, m;
string s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		M[s2] = s1;
	}

	for(int i = 0; i < m; i++) {
		cin >> s1 >> s2;
		cout << s1 << " " << s2 << " #" << M[s2.substr(0,s2.length() - 1)] << "\n";
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int oo = 1e3;
string s, s1;
int ans = oo;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int n = (int) s.length();
	for(int i = 0; i < n; i++) {
		int lo = i, hi = n-1, sub = 0;
		while(lo < hi) {
			if(s[lo++] != s[hi--]) {
				sub++;
			}
		}
		ans = min(ans, sub + i);
	}
	cout << ans << "\n";
	return 0;
}
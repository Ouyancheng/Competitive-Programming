#include<bits/stdc++.h>

using namespace std;

unordered_map<string, int> M;
int len, ci;
string s, cur, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> len >> s) {
		M.clear();
		a = "", cur = "";
		ci = 0;
		while(ci < (int) s.length()) {
			while(ci < (int) s.length() && (int) cur.length() < len) {
				cur += s[ci++];
			}
			M[cur]++;
			if(M[cur] > M[a]) {
				a = cur;
			}
			cur = cur.substr(1);
		}
		cout << a << "\n";
	}
	return 0;
}

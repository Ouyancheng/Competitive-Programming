#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;
vector<int> s[maxn];
int n, s1, s2, s3, s4, s5;
int ans = 0, mcnt = 0;

bool cmp(vector<int> &v1, vector<int> &v2) {
	return lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> s3 >> s4 >> s5;
		s[i].push_back(s1);
		s[i].push_back(s2);
		s[i].push_back(s3);
		s[i].push_back(s4);
		s[i].push_back(s5);
		sort(s[i].begin(), s[i].end());
	}
	sort(s, s + n, cmp);
	for(int i = 0, tcnt = 0; i < n; i++) {
		if(i == 0 || s[i] == s[i-1]) {
			tcnt++;
		} else {
			tcnt = 1;
		}
		mcnt = max(mcnt, tcnt);
	}
	for(int i = 0, tcnt = 0; i < n; i++) {
		if(i == 0 || s[i] == s[i-1]) {
			tcnt++;
		} else {
			tcnt = 1;
		}
		if(tcnt == mcnt) {
			ans += mcnt;
		}
	}
	cout << ans << endl;
	return 0;
}
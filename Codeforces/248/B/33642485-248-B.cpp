#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int w[10], n;
string s, d[1005];
bool fi[10], has[10];
int ass[10], arr[10];
ll ans;

int give(int now) {
	while(has[now]) {
		now++;
	}
	has[now] = 1;
	return now;
}

bool cmp(int i, int j) {
	return w[i] > w[j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		d[i] = s;
		for(int j = (int) s.length() - 1, mul = 1; j >= 0; j--, mul *= 10) {
			int cur = s[j] - 'a';
			w[cur] += mul;
		}
		fi[s[0]-'a'] = 1;
	}
	for(int i = 0; i < 10; i++) {
		arr[i] = i;
	}
	sort(arr, arr+10, cmp);

	for(int i = 0; i < 10; i++) {
		ass[arr[i]] = fi[arr[i]] ? give(1) : give(0);
	}
	for(int i = 0; i < n; i++) {
		for(int j = (int) d[i].length() - 1, mul = 1; j >= 0; j--, mul *= 10) {
			ans += ass[d[i][j]-'a'] * mul;
		}
	}
	cout << ans << "\n";
	return 0;
}
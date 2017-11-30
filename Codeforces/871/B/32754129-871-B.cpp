#include<iostream>
#include<string>

using namespace std;

const int maxn = 5e3+5;

string s;
int dpa[maxn], dpb[maxn], ans, n;

int main() {
	cin >> s;
	int n = (int) s.length();
	for(int i = 0; i < n; i++) {
		dpa[i+1] = (s[i] == 'a');
		dpa[i+1] += dpa[i];
		dpb[i+1] = (s[i] == 'b');
		dpb[i+1] += dpb[i];
	}
	for(int i = 0; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			ans = max(ans, dpa[i] + dpb[j] - dpb[i] + dpa[n] - dpa[j]);
		}
	}
	cout << ans << "\n";
	return 0;
}
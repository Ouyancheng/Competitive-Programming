#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
const int maxn = 1e5+5;
ll f[maxn];
int a[maxn], n;
ll dp[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}
	dp[1] = f[1];
	for(int i = 2; i < maxn; i++) {
		dp[i] = max(dp[i-1],f[i]*i+dp[i-2]);
	}
	cout << dp[maxn-1] << "\n";
	return 0;
}

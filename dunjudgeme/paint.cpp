#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e4+5;
int a[maxn], b[maxn], n;
pair<int, int> c[maxn];
long long ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		c[i] = { b[i], a[i] };
	}	
	sort(c, c+n);
	for(int i = n-1; i >= 0; i--) {
		ans += a[i]+c[i].first*(n-1-i);
	}
	cout << ans << "\n";
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6+5;
int ans, a[maxn], as, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ans = n;
	while(n--) cin >> a[as++];
	sort(a, a+as);
	for(int i = 1; i < as; i++) {
		if(a[i] == a[i-1]) ans--;
	}
	cout << ans << "\n";
	return  0;
}
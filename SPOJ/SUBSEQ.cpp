#include<bits/stdc++.h>

using namespace std;

int t,n,a1,a2;
unordered_map<int,int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	m.reserve(1<<20);
	cin >> t;
	while(t--) {
		long long ans = 0;
		a1 = a2 = 0;
		m.clear();
		cin >> n;
		m[0] = 1;
		for(int i = 1; i <= n; i++) {
			cin >> a2;
			a2 += a1;
			a1 = a2;
			if(m.count(a2-47) > 0) {
				ans += m[a2-47];
			}
			m[a2]++;
		}
		cout << ans << "\n";
	}
	return 0;
}

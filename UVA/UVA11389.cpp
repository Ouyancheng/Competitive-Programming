#include<iostream>
#include<algorithm>

using namespace std;

int m[1000];
int e[1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, d, r;
	while(cin >> n >> d >> r && n != 0) {
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			cin >> m[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> e[i];
		}
		sort(m,m+n);
		sort(e,e+n,greater<int>());
		for(int i = 0; i < n; i++) {
			ans += (max((m[i]+e[i])-d,0)*r);
		}
		cout << ans << "\n";
	}

	return 0;
}

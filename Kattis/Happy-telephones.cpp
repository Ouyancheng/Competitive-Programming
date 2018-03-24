#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4+5;
int n, m, so, de, st, du, a, b, A[maxn], B[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m, n && m) {
		for(int i = 0; i < n; i++) {
			cin >> so >> de >> st >> du;
			A[i] = st, B[i] = st+du-1;
		}
		for(int i = 0; i < m; i++) {
			cin >> a >> b;
			int ans = 0;
			for(int j = 0; j < n; j++) {
				if(!(a+b-1 < A[j] || a > B[j])) {
					ans++;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
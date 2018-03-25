#include<bits/stdc++.h>

using namespace std;

const int oo = INT_MAX;
const int maxn = 15;

int MASK, dp[(1 << maxn) - 1][2], a[maxn], n;

int f(int mask = MASK, int w = 0) {
	if(dp[mask][w] != oo) {
		return dp[mask][w];
	} else if(mask == 0) {
		assert(w == 1);
		return dp[mask][w] = 0;
	}
	if(w == 1) {
		int t = -1, tm = oo;
		for(int i = 0; i < n; i++) {
			if((mask & (1 << i)) == 0) {
				t = a[i] < tm ? i : t;
				tm = min(tm, a[i]);
			}
		}
		assert(t != -1);
		dp[mask][w] = min(dp[mask][w], tm + f(mask | (1 << t), 1 - w));
	} else if(__builtin_popcount(mask) > 1) {
		for(int i = 0; i < n; i++) {
			if((mask & (1 << i))) {
				for(int j = i + 1; j < n; j++) {
					if((mask & (1 << j))) {
						dp[mask][w] = min(dp[mask][w], max(a[i], a[j]) + f(mask & ~(1 << i) & ~(1 << j), 1 - w));
					}
				}
			}
		}
	} else {
		int i = 0;
		for(i = 0; i < n && (mask & (1 << i)) == 0; i++);
		dp[mask][w] = a[i] + f(0, 1);
	}
	return dp[mask][w];
}

int main() {
	cin >> n;
	MASK = (1 << n) - 1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i <= MASK; i++) {
		dp[i][0] = dp[i][1] = oo;
	}
	cout << f() << endl;
}

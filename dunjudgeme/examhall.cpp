#include "examhalls.h"

#include<cstdio>
#include<algorithm>

typedef long long ll;

int tot; 
ll ans = 1e18;
bool dp[1005][50005];

ll cost(int a,int b) {
	return 1LL * a * a + 1LL * b * b;
}

ll solve(int N, int A[]) {
	for(int i = 0; i < N; i++) {
		tot += A[i];
	}
	for(int i = 0; i <= N; i++) dp[i][0] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= tot; j++) {
			if(j - A[i-1] >= 0) {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int j = 0; j <= tot; j++) {
		if(dp[N][j]) {
			ans = min(ans, cost(j,tot-j));
		}
	}
	return ans;
}

ll examhalls(int N, int A[]) {
	return solve(N, A);
}

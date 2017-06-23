#include<cstdio>
#include<algorithm>

using namespace std;

int d[602],cum[602];
int dp[602][301];
const int INF = 1 << 30;

int main(void) {
	int N=0,K=0;
	while(scanf("%d %d",&N,&K) != EOF) {
		for(int i = 1; i <= N+1; i++) {
			scanf("%d",d+i);
			cum[i] = d[i];
		}
		for(int i = 0; i <= N; i++) fill_n(dp[i],K+1,INF);		
		for(int i = 1; i <= N+1; i++) cum[i] += cum[i-1];
		for(int i = 0; i <= N; i++) dp[i][0] = cum[N+1] - cum[i];
		fill_n(dp[N+1],K+1,0);

		for(int k = 1; k <= K && dp[0][K] == INF; k++) {
			for(int j = 1; j <= N+1; j++) {
				for(int i = 0; i <= j; i++) {			
					dp[i][k] = min(dp[i][k],max(cum[j]-cum[i],dp[j][k-1]));        
				}
			}
		}
		printf("%d\n",dp[0][K]);
	}
	return 0;
}

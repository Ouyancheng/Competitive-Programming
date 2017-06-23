#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N,M;
	scanf("%d %d",&N,&M);
	int s[M];
	for(int i = 0; i < M; i++) scanf("%d",s+i);
	sort(s,s+M);
	int ans = 0;
	for(int i = 0; i < M; i++) {
		if(N - s[i] >= 0) {
			N -= s[i];
			ans++;
		} else {
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
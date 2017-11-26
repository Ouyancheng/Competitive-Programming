#include<cstdio>

using namespace std;

#define MAX_N 8005

typedef long long ll;

int L, G;
ll a[MAX_N], dp[2][MAX_N];

ll cost(int l,int r) {
    return 1LL * (r - l + 1) * (a[r] - a[l-1]);
}

void dc(int i,int l,int r,int lo,int hi) {
	if(l > r) return;
	int mid = l + r >> 1, opt = -1;

	dp[i][mid] = 1e17;

	for(int k = lo; k <= mid && k <= hi; k++) {
		ll c = dp[i^1][k] + cost(k+1,mid);
		if(c < dp[i][mid]) {
			dp[i][mid] = c;
			opt = k;
		}
	}
	dc(i,l,mid-1,lo,opt);
	dc(i,mid+1,r,opt,hi);
}

int main() {
	scanf("%d %d",&L,&G);
	for(int i = 1; i <= L; i++) {
		scanf("%lld",&a[i]);
		a[i] += a[i-1];
		dp[1][i] = cost(1,i);
	}
	for(int i = 2; i <= G; i++) {
		dc(i&1,1,L,0,L);
	}
	printf("%lld\n", dp[G&1][L]);
	return 0;
}
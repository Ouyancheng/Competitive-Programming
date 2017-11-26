#include<bits/stdc++.h>

using namespace std;

#define repn(i,e) for(int i = 0; i < e; i++)
#define repsn(i,s,e) for(int i = s; i < e; i++)
#define rrepn(i,s) for(int i = s; i >= 0; i--)
#define rrepsn(i,s,e) for(int i = s; i >= e; i--)

#define MAX_N 4005

const int oo = 1e9;
int n, k;
int dp[2][MAX_N], c[MAX_N][MAX_N];

int readInt () {
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	return result;
}

int cost(int i, int j) {
	int botr = c[j][j];
	int botl = c[j][i-1];
	int topr = c[i-1][j];
	int topl = c[i-1][i-1];
	return (botr - botl - topr + topl) >> 1;
}

void solve(int i, int l, int r, int cl, int cr) {
	if(l > r) return;

	int mid = (l + r) >> 1, opt = -1;
	dp[i][mid] = oo;

	repsn(k,cl,min(mid-1,cr)+1) {
		int newCost = dp[i^1][k] + cost(k+1,mid);
		if(newCost < dp[i][mid]) {
			dp[i][mid] = newCost;
			opt = k;
		}
	}
	solve(i,l,mid-1,cl,opt);
	solve(i,mid+1,r,opt,cr);
}

void work() {
	repsn(i,1,n+1) {
		repsn(j,1,n+1) {
			c[i][j] += c[i][j-1];
		}
	}
	repsn(i,1,n+1) {
		repsn(j,1,n+1) {
			c[i][j] += c[i-1][j];
		}
	}
}

int main(void) {
	n = readInt();
	k = readInt();

	repsn(i,1,n+1) {
		repsn(j,1,n+1) {
			c[i][j] = readInt();
		}
	}
	work();
	repsn(j,1,n+1) {
		dp[1][j] = cost(1,j);
	}
	repsn(i,2,k+1) solve(i&1,1,n,0,n-1);
	printf("%d\n", dp[k&1][n]);
	return 0;
}
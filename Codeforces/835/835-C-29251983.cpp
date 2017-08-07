#include<iostream>
#include<vector>

using namespace std;

#define MAX_N 102

int grid[11][MAX_N][MAX_N];
int n,q,c,aa,bb,cc,dd,x,y,s,t;

int calc(int k,int it,int jt,int ib,int jb) {
	int botr = grid[k][ib][jb];
	int botl = grid[k][ib][jt-1];
	int topr = grid[k][it-1][jb];
	int topl = grid[k][it-1][jt-1];
	return botr - botl - topr + topl;
}

void pre() {
	for(int k = 0; k <= 10; k++) {
		for(int i = 1; i <= MAX_N-1; i++) {
			for(int j = 1; j <= MAX_N-1; j++) {
				grid[k][i][j] += grid[k][i][j-1];
			}
			for(int j = 1; j <= MAX_N-1; j++) {
				grid[k][i][j] += grid[k][i-1][j];
			}
		}
	}
}

int solve(int k,int it,int jt,int ib,int jb) {
	int ans = 0;
	for(int b = 0; b <= 10; b++) {
		int cnt = calc(b,it,jt,ib,jb);
		ans += ((b+k)%(c+1))*cnt;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q >> c;

	for(int i = 1; i <= n; i++) {
		cin >> x >> y >> s;
		grid[s][x][y]++;
	}
	pre();
	for(int i = 1; i <= q; i++) {
		cin >> t >> aa >> bb >> cc >> dd;
		cout << solve(t,aa,bb,cc,dd) << "\n";
	}
	return 0;
}
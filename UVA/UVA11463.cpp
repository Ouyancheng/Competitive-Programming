#include<iostream>

using namespace std;

#define INF 999999999

int cc,n,a,b,r,s,e,ans;
int fw[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> cc;
	for(int i = 0; i < cc; i++) {
		for(int j = 0; j < 100; j++) fill_n(fw[j],100,INF);
		for(int j = 0; j < 100; j++) fw[j][j] = 0;
		ans = -INF;
		cin >> n >> r;
		for(int j = 0; j < r; j++) {
			cin >> a >> b;
			fw[a][b] = fw[b][a] = 1;
		}                             
		cin >> s >> e;
		for(int ii = 0; ii < n; ii++)
			for(int jj = 0; jj < n; jj++)
				for(int kk = 0; kk < n; kk++)
					if(fw[jj][ii] + fw[ii][kk] < fw[jj][kk])
						fw[jj][kk] = fw[jj][ii] + fw[ii][kk];
		for(int ii = 0; ii < n; ii++) {
			ans = max(ans,fw[s][ii] + fw[ii][e]);
		}
		cout << "Case " << i+1 << ": " << ans << endl;
	}
	return 0;
}

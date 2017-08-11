#include<iostream>

using namespace std;

int n,m,ans;
char mat[1005][1005],pat[1005][1005];

void rotate() {
	for(int i = 0; i < m; i++) {
		for(int j = i, tmp = 0; j < m; j++) {
			swap(pat[i][j],pat[j][i]);
		}
	}
	for(int j = 0; j < (m>>1); j++) {
		for(int i = 0, tmp = 0; i < m; i++) {
			swap(pat[i][j],pat[i][m-j-1]);
		}
	}
}

int cnt() {
	int c = 0;
	for(int i = 0; i < n-m+1; i++) {
		for(int j = 0; j < n-m+1; j++) {
			for(int i1 = 0; i1 < m; i1++) {
				for(int j1 = 0; j1 < m; j1++) {
					if(pat[i1][j1] != mat[i+i1][j+j1]) {
						goto next;
					}
				}
			}
			c++;
			next:;
		}
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1) {
		cin >> n >> m;
		if(!n && !m) break;
		ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				cin >> pat[i][j];
			}
		}
		ans = cnt();
		cout << ans << " ";

		rotate();
		ans = cnt();
		cout << ans << " ";

		rotate();
		ans = cnt();
		cout << ans << " ";

		rotate();
		ans = cnt();
		cout << ans << "\n";
	}
	return 0;
}
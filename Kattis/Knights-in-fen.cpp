#include<bits/stdc++.h>

using namespace std;

const int oo = 10001;
int t, si, sj;
char m[5][5], m2[5][5] = { {'1','1','1','1','1'}, {'0','1','1','1','1'}, {'0','0',' ','1','1'}, {'0','0','0','0','1'}, {'0','0','0','0','0'} };
int di[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dj[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
char c;

bool can(int i,int j) {
	if(i < 0 || i > 4 || j < 0 || j > 4)
		return false;
	return true;
}

bool all() {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(m[i][j] != m2[i][j])
				return false;
		}
	}
	return true;
}

int dfs(int i,int j,int pi,int pj,int d=0) {
	if(d > 10) return oo;
	if(all()) return 0;
	int tmp = oo;
	for(int k = 0; k < 8; k++) {
		int ni = i+di[k], nj = j+dj[k];
		if(can(ni,nj) && !(ni == pi && nj == pj)) {
			swap(m[i][j],m[ni][nj]);
			tmp = min(tmp,1+dfs(ni,nj,i,j,d+1));
			swap(m[i][j],m[ni][nj]);
		}
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	cin >> noskipws >> c;
	while(t--) {
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				cin >> noskipws >> m[i][j];
				if(m[i][j] == ' ') {
					si = i;
					sj = j;
				}
			}
			cin >> noskipws >> c;
		}
		int ans = oo;
		if(!all()) {
			ans = min(ans,dfs(si,sj,si,sj));
		} else {
			ans = 0;
		}
		if(ans > 10) {
			cout << "Unsolvable in less than 11 move(s)." << "\n";
		} else {
			cout << "Solvable in " << ans << " move(s)." << "\n";
		}
	}
}

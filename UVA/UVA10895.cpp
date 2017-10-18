#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>


using namespace std;

int n,m,a,b;
int mat[10002][10002];
int t[1002];
vector< pair<int,int> > r[10002];

void work() {
	for(int i = 0; i < max(n,m); i++) {
		for(int j = i+1; j < max(n,m); j++) {
			if(i >= m || j >= n) mat[i][j] = 0;
			swap(mat[i][j],mat[j][i]);
		}
	}
}

void f() {
	for(int i = 0; i < n; i++) {
		r[i].clear();
		for(int j = 0; j < m; j++) {
			if(mat[i][j]) {
				r[i].push_back(make_pair(j+1,mat[i][j]));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> m >> n) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				mat[i][j] = 0;
			}
			cin >> a;
			for(int j = 0; j < a; j++) {
				cin >> t[j];
				t[j]--;
			}
			for(int j = 0; j < a; j++) {
				cin >> b;
				mat[i][t[j]] = b;
			}
		}
		work();
		f();
		cout << n << " " << m << "\n";
		for(int i = 0; i < n; i++) {
			cout << r[i].size();
			for(int j = 0; j < (int) r[i].size(); j++) {
				cout << " " << r[i][j].first;
			}
			cout << "\n";
			for(int j  = 0; j < (int) r[i].size(); j++) {
				cout << r[i][j].second;
				if(j < (int) r[i].size() - 1) {
					cout << " ";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}

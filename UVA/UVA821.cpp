#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 20;
string s;
int a, b, t;
vector<int> G[maxn];
int fw[maxn][maxn];
set<int> S;

void work() {
	long long tot = 0;
	int n = (int) S.size(), lo = *S.begin(), hi = *S.rbegin();

	for(int i = lo; i <= hi; i++) {
		for(int j = lo; j <= hi; j++) {
			if(i != j) {
				fw[i][j] = maxn;
			}
		}
	}

	stringstream ss(s);

	while(ss >> a >> b) {
		if(a == 0 && b == 0) {
			break;
		}
		fw[a][b] = 1;
	}

	for(int k = lo; k <= hi; k++) {
		for(int i = lo; i <= hi; i++) {
			for(int j = lo; j <= hi; j++) {
				if(fw[i][k] + fw[k][j] < fw[i][j]) {
					fw[i][j] = fw[i][k] + fw[k][j];
				}
			}
		}
	}

	for(auto p1 : S) {
		for(auto p2 : S) {
			if(p1 != p2) {
				tot += fw[p1][p2];
			}
		}
	}

	cout << "Case " << ++t << ": " << "average length between pages = " << 1.0 * tot / ((n * (n-1))) << " clicks\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	cout << fixed;
	cin >> ws;
	while(getline(cin, s)) {
		stringstream ss(s);
		S.clear();
		bool yes = 0;
		while(ss >> a >> b) {
			if(a == 0 && b == 0) {
				break;
			}
			yes = 1;
			S.insert(a);
			S.insert(b);
		}
		if(yes) {
			work();
		}
	}
	return 0;
}

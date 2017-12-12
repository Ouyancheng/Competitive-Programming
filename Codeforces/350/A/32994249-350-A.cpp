#include<iostream>
#include<cmath>

using namespace std;

int n, m, ans = -1;
int x[105], y[105];

int chk(int v) {
	bool ex = 0;
	for(int i = 0; i < n; i++) {
		if(x[i] > v) {
			return -1;
		} else if(2*x[i] <= v) {
			ex = 1;
		}
	}
	for(int i = 0; i < m; i++) {
		if(y[i] <= v) {
			return 1;
		}
	}
	return ex ? 0 : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> y[i];
	}
	int lo = 1, hi = 200;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		int c = chk(mid);
		if(c < 0) {
			lo = mid + 1;
		} else {
			if(c == 0) {
				ans = mid;
			}
			hi = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}

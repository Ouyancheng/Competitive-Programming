#include<bits/stdc++.h>

using namespace std;

int n, m, oi;
int out[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n >> m;

	if(n <= m) {
		for(int i = 0; i < m; i++) {
			out[i*2] = 1;
		}
	} else {
		for(int i = 0; i < m; i++) {
			out[i*2+1] = 1;
		}
	}
	oi = max(n*2,m*2);
	for(int i = 0; i < oi; i++) {
		if(out[i] && m) {
			cout << 'G';
			m--;
		} else if(!out[i] && n) {
			cout << 'B';
			n--;
		}
	}
	cout << "\n";
	return 0;
}

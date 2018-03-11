#include<bits/stdc++.h>

using namespace std;

const int maxn = 8;
int t, m[maxn][maxn], conf[100][maxn], ci;
vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7 };

int val(int k) {
	int ans = 0;
	for(int i = 0; i < maxn; i++) {
		ans += m[conf[k][i]][i];
	}
	return ans;
}

bool chk() {
	for(int i = 0; i < maxn; i++) {
		for(int j = i+1; j < maxn; j++) {
			if(abs(j-i) == abs(v[j] - v[i])) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;

	do {
		if(chk()) {
			for(int i = 0; i < maxn; i++) {
				conf[ci][i] = v[i];
			}
			ci++;
		}
	} while(next_permutation(v.begin(), v.end()));

	while(t--) {
		int ans = 0;
		for(int i = 0; i < maxn; i++) {
			for(int j = 0; j < maxn; j++) {
				cin >> m[i][j];
			}
		}
		for(int i = 0; i < 92; i++) {
			ans = max(ans, val(i));
		}
		cout << setw(5) << ans << "\n";
	}
	return 0;
}
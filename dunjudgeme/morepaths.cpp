#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 5e2 + 2;

int n, m, k;
int G[maxn][maxn];
vector<ll> dp[2][maxn];

vector<ll> merge1(vector<ll> &t1, vector<ll> &t2) {
	int i1 = 0, e1 = (int) t1.size();
	int i2 = 0, e2 = (int) t2.size();
	bool can1 = 0, can2 = 0;

	vector<ll> E;

	while(i1 < e1 && i2 < e2 && (int) E.size() < k) {
		if(t1[i1] < t2[i2]) {
			E.push_back(t1[i1++]);
		} else {
			E.push_back(t2[i2++]);
		}
	}

	while(i1 < e1 && (int) E.size() < k) {
		can1 = 1;
		E.push_back(t1[i1++]);
	}

	while(i2 < e2 && (int) E.size() < k) {
		can2 = 1;
		E.push_back(t2[i2++]);
	}
	assert(!(can1 && can2));
	return E;
}

void merge2(vector<ll> &t, ll v) {
	for(int i = 0; i < (int) t.size(); i++) {
		t[i] += v;
	}
}

ll f() {
	for(int i = n-1; i >= 0; i--) {
		for(int j = m-1; j >= 0; j--) {
			vector<ll> t1, t2;
			if(i+1 <= n-1) {
				t1 = dp[(i+1)%2][j];
			}
			if(j+1 <= m-1) {
				t2 = dp[i%2][j+1];
			}

			vector<ll> E = merge1(t1,t2);
			if((int) E.size() == 0) {
				E.push_back(G[i][j]);
			} else {
				merge2(E, G[i][j]);
			}
			dp[i%2][j] = E;
		}
	}
	return -dp[0][0][k-1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> G[i][j];
			G[i][j] = -G[i][j];
		}
	}
	cout << f() << "\n";
	return 0;
}

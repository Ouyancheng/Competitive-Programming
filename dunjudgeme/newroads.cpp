#include<iostream>

using namespace std;


typedef long long ll;

const ll oo = 1e18;
const int maxn = 3e2 +5;

ll m[maxn][maxn];
int n, e, r, a, b, c;
ll sum = 0;

void upd(int u, int v, int w) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sum -= m[i][j];
			ll val = m[i][u] + w + m[v][j];
			if(val < m[i][j]) {
				m[j][i] = m[i][j] = val;
			}
			sum += m[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> e >> r;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			m[i][j] = oo;
			m[j][i] = oo;
		}
	}
	for(int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		m[a][b] = min(m[a][b], 0LL + c);
		m[b][a] = m[a][b];
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(m[i][k] != oo && m[k][j] != oo && m[i][k] + m[k][j] < m[i][j]) {
					m[i][j] = m[i][k] + m[k][j];
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			sum += m[i][j];
		}
	}
	for(int i = 0; i < r; i++) {
		cin >> a >> b >> c;
		upd(a, b, c);
		cout << sum << "\n";
	}
	return 0;
}
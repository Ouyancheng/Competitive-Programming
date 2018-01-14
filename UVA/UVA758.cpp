#include<bits/stdc++.h>

using namespace std;

const int n = 10, m = 15;

struct cell {
	int i, j, d;
	char c;
};

int t;
char a[n][m];
bool vis[n][m];
vector<cell> data;

bool isEmptyCol(int j) {
	bool yes = 1;
	for(int i = 0; i < n; i++) {
		yes &= (a[i][j] == '.');
	}
	return yes;
}

void shiftleft() {
	for(int j = 0, has = 1; j < m - 1 && has; j++) {
		if(!isEmptyCol(j)) {
			continue;
		}
		int t = j + 1;
		while(t < m) {
			if(!isEmptyCol(t)) {
				break;
			}
			t++;
		}
		if(t >= m) {
			has = 0;
			continue;
		}
		for(int i = 0; i < n; i++) {
			a[i][j] = a[i][t];
			a[i][t] = '.';
		}
	}
}

void shiftdown() {
	for(int i = n - 1; i >= 1; i--) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '.') {
				int t = i - 1;
				while(t >= 0 && a[t][j] == '.') {
					t--;
				}
				if(t >= 0) {
					a[i][j] = a[t][j];
					a[t][j] = '.';
				}
			}
		}
	}
}

bool can(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

int dfs(int i, int j, char c, int &ai, int &aj) {
	if(!can(i, j)) {
		return 0;
	}
	if(vis[i][j] || a[i][j] != c) {
		return 0;
	}
	if(j < aj || (j == aj && i > ai)) {
		ai = i, aj = j;
	}
	vis[i][j] = 1;
	return 1 + dfs(i + 1, j, c, ai, aj) + dfs(i - 1, j, c, ai, aj) + dfs(i, j + 1, c, ai, aj) + dfs(i, j - 1, c, ai, aj);
}

bool cmp(const cell &c1, const cell &c2) {
	if(c1.d > c2.d) {
		return 1;
	} else if(c1.d < c2.d) {
		return 0;
	} else if(c1.j < c2.j) {
		return 1;
	} else if(c1.j > c2.j) {
		return 0;
	} else if(c1.i > c2.i) {
		return 1;
	}
	return c1.i == c2.i;
}

void remove(int i, int j, char c) {
	if(!can(i, j)) {
		return;
	}
	if(a[i][j] != c) {
		return;
	}
	a[i][j] = '.';
	remove(i + 1, j, c);
	remove(i - 1, j, c);
	remove(i, j + 1, c);
	remove(i, j - 1, c);
}

// void print() {
// 	for(int i = 0; i < n; i++) {
// 		for(int j = 0; j < m; j++) {
// 			cout << a[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}
// 	cout << endl;
// }

cell go() {
	data.clear();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			vis[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] != '.' && !vis[i][j]) {
				int ai = -1, aj = m;
				int c = dfs(i, j, a[i][j], ai, aj);
				if(c < 2) {
					continue;
				}
				data.push_back({ ai, aj, c, a[i][j] });
			}
		}
	}
	if((int) data.size() > 0) {
		sort(data.begin(), data.end(), cmp);
		remove(data[0].i, data[0].j, data[0].c);
		// cout << "After removal:\n";
		// print();

		shiftdown();
		// cout << "After shifting down:\n";
		// print();


		shiftleft();
		// cout << "After shifting left:\n";
		// print();
		return data[0];
	}
	return { -1, -1, -1, -1 };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	for(int tt = 0, ans = 0, move = 0, cnt = 0; tt < t; tt++, ans = move = cnt = 0)  {
		cnt = n * m;
		for(int i = 0; i < n; i++)  {
			for(int j = 0; j < m; j++)  {
				cin >> a[i][j];
			}
		}
		// print();
		cout << "Game " << tt + 1 << ":\n\n";
		while(1) {
			cell c = go();
			if(!can(c.i, c.j)) {
				break;
			}
			cout << "Move " << ++move <<  " at (" << n - 1 - c.i + 1 << "," << c.j + 1 << "): " << "removed " << c.d << " balls of color " << c.c << ", got " << ((c.d - 2) * (c.d- 2)) << " points.\n";
			ans += (c.d - 2) * (c.d - 2);
			cnt -= c.d;
		}
		cout << "Final score: " << ans + 1000 * (cnt == 0) << ", with " << cnt << " balls remaining.\n";
		cin >> ws;
		if(!cin.eof()) {
			cout << "\n";
		}
	}
	return 0;
}
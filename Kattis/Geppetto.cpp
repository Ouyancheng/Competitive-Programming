#include<bits/stdc++.h>

using namespace std;

const int maxn = 22;
int M[maxn], MAX_MASK, n, m, a, b;

long long dfs(int cur = 0, int mask = MAX_MASK) {
	if(cur == n) return 1;
	if(mask & (1 << cur)) return dfs(cur + 1, mask & M[cur]) + dfs(cur + 1, mask ^ (1 << cur));
	return dfs(cur + 1, mask);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	MAX_MASK = (1 << n) - 1;
	for(int i = 0; i < n; i++) M[i] = MAX_MASK;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		if(M[a] & (1 << b)) M[a] ^= (1 << b);
		if(M[b] & (1 << a)) M[b] ^= (1 << a);
	}
	cout << dfs() << endl;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], b[maxn], o[maxn], n, k;
long long cost;

bool cmp(int i, int j) {
	return (b[i] - a[i]) < (b[j] - a[j]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cost += a[i];
		o[i] = i;
	}
	for(int i = 0;i < n; i++) {
		cin >> b[i];
	}
	sort(o,o+n,cmp);

	for(int i = 0; i < n-k && b[o[i]] - a[o[i]] < 0; i++) {
		cost += b[o[i]] - a[o[i]];
	}
	cout << cost << "\n";

	return 0;
}
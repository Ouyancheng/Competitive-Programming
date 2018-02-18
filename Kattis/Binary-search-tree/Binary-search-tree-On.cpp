#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;

int n, a[maxn], l[maxn], fw[maxn], bw[maxn], L[maxn], R[maxn];
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		fw[i] = i+1;
		bw[i] = i-1;
	}

	for(int i = n; i >= 1; i--) {
		int cur = a[i];
		if(bw[cur] == 0 && fw[cur] != n+1) {
			R[cur] = fw[cur];
		} else if(bw[cur] != 0 && fw[cur] == n+1) {
			L[cur] = bw[a[i]];
		} else if(bw[cur] != 0 && fw[cur] != n+1) {
			L[cur] = bw[cur];
			R[cur] = fw[cur];
		}
		fw[bw[cur]] = fw[cur];
		bw[fw[cur]] = bw[cur];
	}

	for(int i = 1; i <= n; i++) {
		int cur = a[i];
		if(L[cur] == 0 && R[cur] != 0) {
			l[cur] = l[R[cur]] + 1;
		} else if(L[cur] != 0 && R[cur] == 0) {
			l[cur] = l[L[cur]] + 1;
		} else if(L[cur] != 0 && R[cur] != 0) {
			l[cur] = (l[L[cur]] < l[R[cur]]) ? l[R[cur]] + 1: l[L[cur]] + 1;
		}
		ans += l[a[i]];
		cout << ans << "\n";
	}
}

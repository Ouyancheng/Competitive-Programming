#include<iostream>

using namespace std;

const int maxn = 1e5 + 5;

int n, q, a[maxn];
int dc[maxn], ic[maxn];

bool qr(int l, int r) {
	if(l + dc[l] > r || l + ic[l] > r) {
		return 1;
	}
	return l + ic[l] + dc[l + ic[l]] > r;
}

void proc() {
	int lo = 0, hi = 0;
	while(lo < n) {
		hi++;
		while(hi < n && a[hi] <= a[hi-1]) {
			hi++;
		}
		hi--;
		int len = hi - lo + 1;
		while(lo <= hi) {
			dc[lo] = len--;
			lo++;
		}
		lo = ++hi;
	}

	lo = hi = 0;
	while(lo < n) {
		hi++;
		while(hi < n && a[hi] >= a[hi-1]) {
			hi++;
		}
		hi--;
		int len = hi - lo + 1;
		while(lo <= hi) {
			ic[lo] = len--;
			lo++;
		}
		lo = ++hi;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, r;

	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	proc();
	for(int i = 0; i < q; i++) {
		cin >> l >> r;
		if(qr(--l, --r)) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << "\n";
	}
	return 0;
}
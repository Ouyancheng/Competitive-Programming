#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int maxn = 1e5 + 5;

typedef long long ll;

int a[maxn], r[maxn], l[maxn], x, k, n;
int lo, hi;

void work() {
	for(int i = 1; i <= n; i++) {
		r[i] = a[i]/x;
		l[i] = (a[i]-1)/x;
	}
}

ll go() {
	ll tot = 0;

	for(int i = 1; i <= n; i++) {
		int lo = 1, hi = n, far = -1, near = -1;
		while(lo <= hi) {
			int mid = lo + hi >> 1;
			if(a[mid] < a[i]) {
				lo = mid + 1;
			} else if(r[mid] - k == l[i]) {
				far = mid;
				lo = mid + 1;
			} else if(r[mid] - k > l[i]) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		lo = 1, hi = n;
		while(lo <= hi) {
			int mid = lo + hi >> 1;
			if(a[mid] < a[i]) {
				lo = mid + 1;
			} else if(r[mid] - k == l[i]) {
				near = mid;
				hi = mid - 1;
			} else if(r[mid] - k > l[i]) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		if(far != -1 && near != -1) {
			tot += far - near + 1;
		}
	}
	return tot;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	work();
	cout << go() << "\n";
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct interval {
	int left;
	int right;
};

int n,d,a,b,ans = 1;
interval ar[50005];

bool cmp(const interval &i, const interval &j) {
	if(i.left == j.left) {
		return i.right > j.right;
	}
	return i.left < j.left;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> d >> n;
	if(n == 0 && d != 0) {
		cout << -1 << "\n";
		return 0;
	} else if(n == 0 && d == 0) {
		cout << 0 << "\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		ar[i].left = max(0,a - b);
		ar[i].right = min(d,a + b);
	}
	sort(ar,ar+n,cmp);
	interval c = ar[0];
	int best = 0, lo = c.left, hi = c.right, cur = 1, ocur = 1;
	while(cur < n && hi < d) {
		int far = c.right;
		ocur = cur;
		while(cur < n && ar[cur].left <= c.right) {
			if(ar[cur].right > far) {
				far = ar[cur].right;
				best = cur;
			}
			cur++;
		}
		if(cur == ocur) break;
		c = ar[best];
		hi = max(hi,c.right);
		ans++;
	}
	if(lo == 0 && hi >= d) {
		cout << ans;
	} else {
		cout << -1;
	}
	cout << "\n";
	return 0;
}

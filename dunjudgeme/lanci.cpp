#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 5e5 + 5;
int n, a[maxn], ones;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(n == 1) {
		cout << 0 << "\n";
	} else {
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a + n);

		int cur = 0;

		while(ones < n-1) {
			if(a[cur] == 1) {
				n--;
				a[cur++]--;
			} else {
				a[cur]--;
			}
			ones++;
		}
		cout << ones << "\n";
	}
	return 0;
}

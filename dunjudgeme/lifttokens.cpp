#include<bits/stdc++.h>

using namespace std;

int arr[] = { 10000, 5000, 1000, 500, 100, 50, 10, 5, 1 };

int n, k, ans = (int) 1e9;

int main() {
	cin >> n;
	while(k <= 4) {
		int cur = n, i = 0, t = 0;
		if(k * 17 <= cur) {
			cur -= k * 17;
			t += k;
		}
		while(cur) {
			t += cur/arr[i];
			cur %= arr[i];
			i++;
		}
		ans = min(ans, t);
		k++;
	}
	cout << ans << "\n";
	return 0;
}
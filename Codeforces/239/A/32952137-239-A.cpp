#include<iostream>

using namespace std;

int y, k, n, maxx, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> y >> k >> n;
	for(int i = k; i <= n/k * k; i += k) {
		if(i - y <= 0) continue;
		cnt++;
		cout << i-y << " ";
	}
	if(!cnt) {
		cout << -1;
	}
	cout << "\n";
	return 0;
}
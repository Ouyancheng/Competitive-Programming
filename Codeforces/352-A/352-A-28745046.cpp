#include<iostream>

using namespace std;

int n,a;
int cnt[6];
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
		sum += a;
	}
	if(cnt[0] == 0) {
		cout << -1;
	} else if(sum/45 == 0) {
		cout << 0;
	} else {
		int k = sum/45*9;
		for(int i = 1; i <= k; i++) {
			cout << 5;
		}
		for(int i = 1; i <= cnt[0]; i++) {
			cout << 0;
		}
	}
	cout << "\n";
	return 0;
}
#include<iostream>

using namespace std;

int n, a;
int mon[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a == 25) {
			mon[0]++;
		} else if(a == 50) {
			mon[1]++;
		} else {
			mon[2]++;
		}
		int change = a - 25;
		if(change >= 100) {
			int num = min(change/100,mon[2]);
			change -= num * 100;
			mon[2] -= num;
		}
		if(change >= 50) {
			int num = min(change/50,mon[1]);
			change -= num * 50;
			mon[1] -= num;
		}
		if(change >= 25) {
			int num = min(change/25,mon[0]);
			change -= num * 25;
			mon[0] -= num;
		}
		if(change != 0) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";
	return 0;
}
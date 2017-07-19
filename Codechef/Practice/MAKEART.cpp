#include<iostream>

using namespace std;

int n,t;
int arr[100005];
bool flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int cc = 0; cc < t; cc++) {
		flag = false;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for(int i = 0; i < n; i++) {
			int cur = arr[i];
			int cnt = 0;
			while(i < n) {
				if(arr[i] == cur) {
					cnt++;
					i++;
				} else {
					break;
				}
			}
			if(cnt >= 3) {
				flag = true;
				break;
			} else {
				i--;
			}
		}
		if(flag) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}
	return 0;
}
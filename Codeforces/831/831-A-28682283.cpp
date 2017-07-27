#include<bits/stdc++.h>

using namespace std;

int n, arr[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n) {
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		arr[n+1] = 0;
		int hi = *max_element(arr,arr+n+1);
		int j = 0;
		while(arr[j] < arr[j+1]) {
			j++;
		}
		while(arr[j] == hi) {
			j++;
		}
		while(arr[j] > arr[j+1]) {
			j++;
		}
		if(j != n+1) {
			cout << "NO";
		} else {
			cout << "YES";
		}
		cout << "\n";
	}
	return 0;
}
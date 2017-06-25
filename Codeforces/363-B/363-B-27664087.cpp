#include<iostream>

using namespace std;

int lo, hi;

int n,k;
int arr[200005];
int ans = 1 << 30;
int id;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++) {
		arr[i] += arr[i-1];
	}
	for(int i = k; i <= n; i++) {
		int diff = arr[i] - arr[i-k];
		if(diff < ans) id = i-k+1;
		ans = min(ans,diff);
	}
	cout << id << "\n";
	return 0;
}
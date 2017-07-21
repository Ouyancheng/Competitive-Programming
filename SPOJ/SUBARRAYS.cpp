#include<bits/stdc++.h>

using namespace std;

int n,k;
int arr[100005],dq[100005];
int hi,lo;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	for(int i = 0; i < k; i++) {
		while(lo < hi && arr[i] >= arr[dq[hi-1]]) hi--;
		dq[hi++] = i;
	}

	cout << arr[dq[lo]];
	for(int i = k; i < n; i++) {
		while(lo < hi && dq[lo] < i - k + 1) lo++;
		while(lo < hi && arr[i] >= arr[dq[hi-1]]) hi--;
		dq[hi++] = i;
		cout << " " << arr[dq[lo]];	
	}
	cout << "\n";
	return 0;
}
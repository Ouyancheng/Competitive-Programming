#include<iostream>
 
using namespace std;
 
int n;
long long m, k, arr[55];
 
int main() {
	cin >> k; n = 50;
	for(int i = 0; i < n; i++) arr[i] = i;
	m = 1LL * k/n;
	for(int i = 0; i < n; i++) {
		arr[i] += m;
	}
	for(int i = 0; i < k % n; i++) {
		for(int j = 0; j < n; j++) {
			if(j == i) {
				arr[j]+=n;
			} else {
				arr[j]--;
			}
		}
	}
	cout << n << "\n";
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << "\n";
	return 0;
}
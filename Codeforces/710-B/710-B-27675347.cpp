#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;

int n;
int arr[350000];
long long ls[350000], rs[350000];
int a,b,e;
long long diff = LLONG_MAX, sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr,arr+n);
	for(int i = 1; i < n; i++) {
		sum += (1LL * i * (long long)abs(arr[i]-arr[i-1]));
		ls[i] += sum;
	}
	sum = 0;
	for(int i = n-2; i >= 0; i--) {
		sum += (1LL * (n-2-i+1) * (long long)abs(arr[i+1]-arr[i]));
		rs[i] += sum;
	}
	for(int i = 0; i < n; i++) {
		if(ls[i] + rs[i] < diff) {
			e = arr[i];
			diff = ls[i] + rs[i];
		}
	}
	cout << e << "\n";
	return 0;
}
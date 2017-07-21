#include<iostream>
#include<algorithm>

using namespace std;

int a,b,ans,arr[100];

int main() {
	cin >> a >> b;
	for(int i = 0; i < a; i++) {
		cin >> arr[i];
	}
	sort(arr,arr+a);
	reverse(arr,arr+a);
	for(int i = 0; i < b; i++) {
		ans += arr[i];
	}
	cout << ans << "\n";
	return 0;
}
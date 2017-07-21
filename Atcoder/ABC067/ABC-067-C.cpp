#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

#define ll long long

int n;
ll arr[200005];
ll ans = LLONG_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	for(int i = 1; i <= n-1; i++) {
		ll sum1 = arr[i], sum2 = arr[n] - arr[i];
		ans = min(ans,abs(sum1-sum2));
	}
	cout << ans << "\n";
	return 0;
}
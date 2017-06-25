#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll powof2[32];
int arr[100005];
unordered_map<ll,int> us;
ll ans;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	powof2[0] = 1;
	for(int i = 1; i <= 31; i++) {
		powof2[i] = powof2[i-1] << 1;
	}
	for(int i = 0; i <= 31; i++) {
		us.clear();
		for(int j = 0; j < n; j++) {
			if(us.find(powof2[i] - arr[j]) != us.end()) {
				ans += us[powof2[i] - arr[j]];
			}
			us[arr[j]]++;
		}
	}
	cout << ans << "\n";
	return 0;
}
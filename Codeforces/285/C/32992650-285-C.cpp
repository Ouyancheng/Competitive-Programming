#include<iostream>
#include<algorithm>

using namespace std;

long long ans;
int a[(int)3e5+5], n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0; i < n; i++) {
		ans += abs(0LL + a[i] - (i+1));
	}
	cout << ans << "\n";
	return 0;
}

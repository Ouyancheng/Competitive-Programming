#include<iostream>

using namespace std;

int n,p,lo,ans;
long long sum;
int a[1000000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		while(sum > p) {
			sum -= a[lo++];
		}
		ans = max(ans,i-lo+1);
	}
	cout << ans << "\n";
	return 0;
}
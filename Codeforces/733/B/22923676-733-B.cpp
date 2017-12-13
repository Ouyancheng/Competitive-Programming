#include<iostream>
#include<cmath>

using namespace std;

#define ll long long

int N, a[100010], b[100010], ans = 0;
ll ta, tb, tc, md;

int main(void) {
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i] >> b[i];
		ta += a[i], tb += b[i];
	}
	tc = abs(ta-tb);
	for(int i = 1; i <= N; i++) {
		ll sum = abs(ta-a[i]+b[i]-(tb-b[i]+a[i]));
		if(sum > tc) ans = i;
		tc = max(tc,sum);
	}
	cout << ans << endl;
	return 0;
}
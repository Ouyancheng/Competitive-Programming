#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
	long long n,m,k,x,s;
	cin >> n >> m >> k >> x >> s;
	long long s1[m+1], c1[m+1], s2[k+1], c2[k+1];
	long long ans = n * x;
	s1[0] = x;
	c1[0] = s2[0] = c2[0] = 0;

	for(int i = 1; i <= m; i++) cin >> s1[i];
	for(int i = 1; i <= m; i++) cin >> c1[i];
	for(int i = 1; i <= k; i++) cin >> s2[i];
	for(int i = 1; i <= k; i++) cin >> c2[i];

	for(int i = 0; i <= m; i++) {
		if(s-c1[i] >= 0) {
			int q = upper_bound(c2,c2+k+1,s-c1[i]) - c2 - 1;
			ans = min(ans,s1[i] * (n - s2[q]));
		}
	}
	cout << ans << endl;

	return 0;
}
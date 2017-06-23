#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[32770],w[32770],ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n) {
		ans = 0;
		fill_n(w,1<<n,0);
		for(int i = 0; i < (1 << n); i++) {
			cin >> a[i];
		}
		for(int c = 0; c < (1 << n); c++) {
			for(int k = 0; k < n; k++) {
				w[c] += a[c ^ (1<<k)];
			}
		}
		for(int c = 0; c < (1 << n); c++) {
			for(int k = 0; k < n; k++) {
				ans = max(ans,w[c ^ (1<<k)]+w[c]);
			}
		}
		cout << ans << "\n";
	}
}
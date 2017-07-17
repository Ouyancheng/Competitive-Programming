#include<iostream>
 
using namespace std;
 
int t,ans,n,a,lim;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
 
	while(t--) {
		ans = 0;
		lim = (int) ((1LL << 31)-1);
		cin >> n;
		while(n--) {
			cin >> a;
			if(a <= lim) {
				ans++;
				lim = a;
			}
		}
		cout << ans << "\n";
	}
} 
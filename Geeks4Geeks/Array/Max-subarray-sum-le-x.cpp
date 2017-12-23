#include <iostream>
#include <climits>
using namespace std;

int a[1005], t, sum, x, ans, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
     sum = 0;
     ans = INT_MIN;
     cin >> n;
     for(int i = 0; i < n; i++) {
	    cin >> a[i];
	 }
	 cin >> x;
	 int tail = 0;
	 for(int i = 0; i < n; i++) {
	   sum += a[i];
	   while(sum > x)
	     sum -= a[tail++];
	   ans = max(ans,sum);
	 }
	 cout << ans << "\n";
    }
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int cc, n, a1[1005], a2[1005];
long long ans = 0;

int main() {
	//code
	cin >> cc;
	for(int i = 0;  i < cc; i++) {
	    ans = 0;
	    cin >> n;
	    for(int j = 0; j < n; j++) {
	        cin >> a1[j];
	    }
	    for(int j = 0; j < n; j++) {
	        cin >> a2[j];
	    }
	    sort(a1,a1+n);
	    sort(a2,a2+n);
	    for(int j = 0; j < n; j++) {
	        ans += a1[j] * a2[j];
	    }
	    cout << ans << endl;
	}
	return 0;
}
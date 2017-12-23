#include <iostream>
#include<climits>
using namespace std;

int t[1000];
int q[1000];

int a,n,T,lo,hi,ans;

int main() {
	//code
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for(int i = 0; i < T; i++) {
	    cin >> n;
	    fill(t,t+n,INT_MAX);
	    lo = hi = ans = 0;
	    for(int j = 0; j < n; j++) {
	        cin >> a;
	        if(a) {
	            q[hi++] = j;
	            t[j] = 0;
	        }
	    }
	    while(hi - lo > 0) {
	        int e = q[lo++];
	        if(e-1 >= 0 && t[e-1] == INT_MAX) {
	            t[e-1] = t[e] + 1;
	            q[hi++] = e-1;
	        }
	        if(e+1 < n && t[e+1] == INT_MAX) {
	            t[e+1] = t[e] + 1;
	            q[hi++] = e+1;
	        }
	    }
	    bool flag = true;
	    for(int j = 0; j < n; j++) {
	        ans = max(ans,t[j]);
	        flag &= (t[j] == INT_MAX);
	    }
	    if(flag) {
	        cout << "-1" << "\n";
	    } else {
	        cout << ans << "\n";
	    }
	}
	return 0;
}
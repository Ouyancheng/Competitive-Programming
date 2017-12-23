#include <bits/stdc++.h>

using namespace std;

int t,n,k,a[100005];
vector<int> v;
bool can[100005];
long long sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
	    cin >> n;
	    sum = 0;
	    fill(can,can+n,1);
	    v.clear();
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    cin >> k;
	    for(int i = 0; i < n; i++) {
	        if(a[i] == k) {
	            v.push_back(i);
	        } else if(a[i] > k) {
	            can[i] = false;
	        }
	    }
	    for(int i = 0; i < (int) v.size(); i++) {
	        //cout << "value of v[i] is: " << v[i] << "\n";
	        int cur = v[i], lb = v[i], rb = v[i];
	        if(!can[cur]) continue;
	        can[cur] = 0;
	        while(lb > 0 && can[lb-1]) {
	            can[lb-1] = 0;
	            lb--;
	        }
	        while(rb < n-1 && can[rb+1]) {
	            can[rb+1] = 0;
	            rb++;
	        }
	        //cout << "lb: " << lb << " rb: " << rb << "\n";
	        sum += rb - lb + 1;
	    }
	    cout << sum << "\n";
	}
	return 0;
}
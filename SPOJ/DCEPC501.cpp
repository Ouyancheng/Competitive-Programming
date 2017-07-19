#include<iostream>
#include<iomanip>

using namespace std;

#define ll long long

int n,t,arr[100005];
ll dp[100005][4];

ll f(int i,int t) {
	if(i >= n) {
		return 0;
	} else if(dp[i][t]) {
		return dp[i][t];
	} else {
		ll p1 = 0, p2 = 0, p3 = 0;
		p1 = arr[i];
		if(t >= 2 && i < n-1) p2 = p1 + arr[i+1];
		if(t == 3 && i < n-2) p3 = p2 + arr[i+2];
		
		ll c1 = p1+max(f(i+2,1),max(f(i+2,2),f(i+2,3)));
		ll c2 = p2+max(f(i+4,1),max(f(i+4,2),f(i+4,3)));
		ll c3 = p3+max(f(i+6,1),max(f(i+6,2),f(i+6,3)));
		return dp[i][t] = max(c1,max(c2,c3));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 1; j <= 3; j++) {
				dp[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << max(f(0,1),max(f(0,2),f(0,3))) << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1005

int n,t;
int dp[MAX_N][2], arr[MAX_N];

int f(int i,int c) {
    if(i >= n) return 0;
    if(dp[i][c] != -1) return dp[i][c];
    if(c) {
        return dp[i][c] = arr[i] + max(f(i+2,1),f(i+2,0));
    } else {
        return dp[i][c] = max(f(i+1,1),f(i+1,0));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
    	for(int i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1;
    	for(int i = 0; i < n; i++) cin >> arr[i];
    	cout << max(f(0,0),f(0,1)) << "\n";
    }
	return 0;
}
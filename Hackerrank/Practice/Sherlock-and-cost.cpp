#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000][2];
int n,cc;
int b[100000];

int f(int cur,int r) {
    if(cur == n-1) {
        return dp[cur][r] = 0;
    } else if(dp[cur][r] != -1) {
        return dp[cur][r];
    } else if(r) {
        dp[cur][1] = abs(b[cur] - b[cur+1]) + f(cur+1,1);
        dp[cur][1] = max(dp[cur][1],abs(b[cur] - 1) + f(cur+1,0));
        return dp[cur][1];
    } else {
        dp[cur][0] = abs(1 - b[cur+1]) + f(cur+1,1);
        return dp[cur][0];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    cin >> cc;
    for(int i = 0; i < cc; i++) {
        cin >> n;
        for(int j = 0; j < 100000; j++) dp[j][0] = dp[j][1] = -1;
        for(int j = 0; j < n; j++) {
            cin >> b[j];
        }
        cout << max(f(0,1),f(0,0)) << endl;
/*
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 2; k++) {
                cout << dp[j][k] << " ";
            }
            cout << endl;
        }
*/
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[37];
int c,n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for(int i = 4; i <= 36; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> n;
        cout << dp[n] << "\n";   
    }
    return 0;
}

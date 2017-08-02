#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int N, r[100010];
long long dp[100010];

long long f() {
    for(int i = 1; i <= N; i++) {
        if(r[i] > r[i-1]) {
            dp[i]=dp[i-1]+1;
        }
    }
    for(int i = N; i >= 1; i--) {
        if(r[i] > r[i+1] && dp[i+1]>=dp[i]) {
            dp[i]=dp[i+1]+1;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += dp[i];
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> N;
    fill_n(dp,N+1,1);
    r[0] = r[N+1] = 1 << 30;
    for(int i = 1; i <= N; i++) {
        cin >> r[i];
    }
    cout << f() << endl;
    return 0;
}

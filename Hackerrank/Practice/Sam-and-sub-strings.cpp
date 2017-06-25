#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define L 1000000007

string s;
int n;
ll ans = 0;
ll dp[300000];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        dp[i] = dp[i-1] * 10 + (s[i]-'0') * (i+1);
        dp[i] %= L;
        ans = (ans + dp[i])%L;
    }
    cout << ans << endl;
    return 0;
}

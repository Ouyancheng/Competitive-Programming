#include<iostream>

using namespace std;

int n, t;
long long ans;
int md = 1000000007;
long long dp0[75];
long long dp1[75];

void f() {
    dp0[0] = dp1[0] = dp0[1] = dp1[1] = 1;
    for(int i = 2; i <= 70; i++) {
        dp0[i] = dp0[i-1] + dp1[i-1];
        dp1[i] = dp0[i-1];
    }
}

int main(void) {
    cin >> n;
    while(n--) {
        ans = 0;
        cin >> t;
        f();
        cout << (dp0[t]+dp1[t])%md << endl;
    }
    return 0;
}
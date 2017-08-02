#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <utility>
using namespace std;

#define ll long long

int n,k,tail;
int a[100001];
ll sum[100001];
ll ans = 1LL << 60,tmp;

//dp[k] --> maximum unfairness in a group of size k

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i];
    }
    sort(a,a+n+1);
    sort(sum,sum+n+1);
    for(int i = 0; i < n; i++) {
        sum[i+1] += sum[i];
    }
    for(int i = 2; i <= k; i++) {
        tmp += ((ll) (i-1)) * a[i] - (sum[i-1]-sum[0]);
    }
    ans = tmp;
    for(int i = k + 1, tail = 1; i <= n; i++,tail++) {
        tmp += ((ll) k) * a[i] - (sum[i-1]-sum[tail-1]);
        tmp -= ((sum[i]-sum[tail]) - ((ll) k) * a[tail]);
        ans = min(ans,tmp);
    }
    cout << ans << "\n";
    return 0;
}

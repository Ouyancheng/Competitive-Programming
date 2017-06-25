#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long a[100001];
long long ans = 1LL << 60;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0; i < n-1; i++) {
        ans = min(ans,abs(a[i]-a[i+1]));
    }
    cout << ans << "\n";
    return 0;
}

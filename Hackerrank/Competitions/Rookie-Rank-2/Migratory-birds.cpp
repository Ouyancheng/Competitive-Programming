#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f[6];
int n,t;
int ans;
int hi;
    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> t;
        f[t]++;
        if(f[t] > hi) {
            hi = f[t];
            ans = t;
        } else if(f[t] == hi) {
            ans = min(ans,t);
        }
    }
    cout << ans << "\n";
    return 0;
}

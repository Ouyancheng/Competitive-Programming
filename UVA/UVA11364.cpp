#include<bits/stdc++.h>

using namespace std;

int a, n, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int hi = 0, lo = 1e9;
        for(int i = 0; i < n; i++) {
            cin >> a;
            hi = max(hi, a);
            lo = min(lo, a);
        }
        cout << abs(hi - lo) * 2 << "\n";;
    }
    return 0;
}
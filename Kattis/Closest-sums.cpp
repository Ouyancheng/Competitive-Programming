#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n,q,a[1000],t,lo,hi,cc;

int f() {
    lo = 0, hi = n-1;
    int ans = 1 << 30;
    while(lo < hi) {
        if(abs(a[lo] + a[hi] - t) < abs(ans - t)) ans = a[lo] + a[hi];
        if(a[lo] + a[hi] < t) {
            lo++;
        } else if(a[lo] + a[hi] > t) {
            hi--;
        } else {
            break;
        }       
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n) {
        cout << "Case " << ++cc << ": " << "\n";
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a,a+n);
        cin >> q;
        while(q--) {
            cin >> t;
            cout << "Closest sum to " << t << " is " << f() << ".\n";
        }
    }
    return 0;
}
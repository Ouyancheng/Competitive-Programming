#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a,t,n;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a;
            ans ^= a;
        }
        if(ans) cout << "First";
        else cout << "Second";
        cout << "\n";
    }
    return 0;
}

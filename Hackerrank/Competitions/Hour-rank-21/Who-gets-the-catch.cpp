#include <bits/stdc++.h>
using namespace std;

int c[1005], s[1005];
double best = INT_MAX;
int cnt = 0, idx = 0, n, x;
const int eps = 1e-10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        best = min(best,fabs(x-c[i])/s[i]);
    }
    for(int i = 0; i < n; i++) {
        if(fabs(best - fabs(x-c[i])/s[i]) <= eps) {
            idx = i;
            cnt++;
        }
    }
    if(cnt > 1) {
        cout << -1 << "\n";
    } else {
        cout << idx << "\n";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e2;
int a[maxn], b[maxn], n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> x;
            a[x] = i;
        }
        for(int i = 1; i <= n; i++) {
            cin >> x;
            b[x] = i;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i] < a[j] && b[j] < b[i]) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}
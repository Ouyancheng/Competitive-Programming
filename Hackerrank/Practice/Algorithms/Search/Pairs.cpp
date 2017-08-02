#include <bits/stdc++.h>
using namespace std;

int n,k,a;
unordered_map<int,int> m;
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a;
        ans += m[a-k];
        ans += m[a+k];
        m[a]++;
    }
    cout << ans << "\n";
    return 0;
}

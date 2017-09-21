#include<bits/stdc++.h>

using namespace std;

int n, s[11], b[11];

long long calc(int mask) {
    long long ss = 1,bb = 0;
    for(int i = 0; (1 << i) <= mask; i++) {
        if(mask & (1 << i)) {
            ss *= s[i];
            bb += b[i];
        }
    }
    return abs(ss-bb);
}

long long bf(int i=0,int mask=0) {
    if(i == n) return mask == 0 ? 1e18 : calc(mask);
    long long ans1 = bf(i+1,mask);
    long long ans2 = bf(i+1,mask|(1 << i));
    return min(ans1,ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }
    cout << bf() << "\n";
    return 0;
}
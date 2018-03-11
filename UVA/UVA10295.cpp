#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int a, n, t;
map<string, int> M;
string s, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        cin >> s >> a;
        M[s] = a;
    }
    while(t--) {
        ll ans = 0;
        cin >> ws;
        while(getline(cin, s)) {
            if(s[0] == '.') {
                break;
            }
            stringstream ss(s);
            while(getline(ss, s2, ' ')) {
                ans += M[s2];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
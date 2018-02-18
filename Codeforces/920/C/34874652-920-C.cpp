#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int n, a[maxn], o;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;
    s += "0";
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '1') {
            o++;
        } else {
            o = 0;
        }
        if(a[i] > i+1) {
            if(o < a[i] - (i+1)) {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
    return 0;
}
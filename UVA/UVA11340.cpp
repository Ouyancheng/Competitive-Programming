#include<bits/stdc++.h>

using namespace std;

char c;
int a, b, n, t;
map<char, int> M;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(2);
    cout << fixed;
    cin >> t;
    while(t--) {
        int ans = 0;
        M.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> c >> b;
            M[c] = b;
        }
        cin >> n;
        cin >> ws;
        for(int i = 0; i < n; i++) {
            getline(cin, s);
            for(char ch : s) {
                ans += M[ch];
            }
        }
        cout << 1.0 * ans / 100 << "$" << "\n";
    }
    return 0;
}
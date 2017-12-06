#include<iostream>

using namespace std;

int n, a[105], b[105], top, bot;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        top += a[i];
        bot += b[i];
    }
    if(top % 2 == 1 && bot % 2 == 1) {
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0 && b[i] % 2 == 1 || a[i] % 2 == 1 && b[i] % 2 == 0) {
                cout << 1 << "\n";
                return 0;
            }
        }
        cout << -1 << "\n";
    } else if(top % 2 == 0 && bot % 2 == 0) {
        cout << 0 << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
#include<iostream>

using namespace std;

const int maxn = 1e6 + 5;
int t, a, b;
int diff[maxn*3];

void calc() {
    int cur = 1, add = 1;
    diff[0] = 0;
    while(cur < maxn) {
        diff[cur] = add;
        diff[cur + add] = -add;
        add++;
        while(cur < maxn && diff[cur]) {
            cur++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    calc();

    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a - b == diff[a] || a - b == diff[b]) {
            cout << "Bunty";
        } else {
            cout << "Dolly";
        }
        cout << "\n";
    }
    return 0;
}
#include<iostream>

using namespace std;

int a, b, c;
int ans, d[1000005];
const int mod = 1073741824;

void calc() {
    for(int i = 1; i <= a*b*c; i++) {
        for(int j = i; j <= a*b*c; j += i) {
            d[j]++;
        }
    }
}

int main() {
    cin >> a >> b >> c;
    calc();
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            for(int k = 1; k <= c; k++) {
                ans = (0LL + ans + d[i*j*k]) % mod;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
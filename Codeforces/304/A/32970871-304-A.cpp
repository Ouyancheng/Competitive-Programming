#include<iostream>
#include<cmath>

using namespace std;

int x, y, n, ans;

int main() {
    cin >> n;
    for(x = 1; x <= n; x++) {
        for(y = x; y <= n; y++) {
            double f = sqrt(x * x + y * y);
            if(f - int(f) > 1e-12) {
                continue;
            }
            int z = (int) f;
            if(z > n) break;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
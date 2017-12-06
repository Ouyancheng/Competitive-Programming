#include<iostream>
#include<cmath>
#include<cassert>

using namespace std;

typedef long long ll;
int x, y, n, ans;
bool used[10005][10005];

int main() {
    cin >> n;
    bool can = true;
    for(ll k = 1; can; k++) {
        can = false;
        for(x = 1; x <= n; x++) {
            for(y = 1; y < x; y++) {
                ll xs = x * x, ys = y * y;
                ll a = k * (xs - ys);
                ll b = k * 2 * x * y;
                ll c = k * (xs + ys);
                if(c > n) break;
                if(b < a) swap(a,b);
                can = true;
                if(used[(int)a][(int)b]) continue;
                used[(int)a][(int)b] = 1;
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

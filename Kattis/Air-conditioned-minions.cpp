#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ii pair<int,int>

int n,a,b,lo,hi,ans;
vector<ii> v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lo = hi = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.pb(mp(a,b));
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++) {
        a = v[i].fi, b= v[i].se;
        if(a > hi) {
            ans++;
            lo = a, hi = b;
        } else {
            lo = max(lo,a);
            hi = min(hi,b);
        }
    }
    cout << ans << "\n";

    return 0;
}

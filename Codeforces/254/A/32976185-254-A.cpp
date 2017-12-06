#include<bits/stdc++.h>

using namespace std;

int a[(int) 6e5+5];
int dat[5005], pre[5005];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n;
    n *= 2;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dat[a[i]]++;
    }
    for(int i = 1; i <= 5000; i++) {
        if(dat[i]&1) {
            cout << -1 << "\n";
            return 0;
        }
        pre[i] = -1;
    }
    for(int i = 1; i <= n; i++) {
        if(pre[a[i]] != -1) {
            cout << pre[a[i]] << " " << i << "\n";
            pre[a[i]] = -1;
        } else {
            pre[a[i]] = i;
        }
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n, a;
int arr[12];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        long long ans = 0;
        for(int j = 0; j < 12; j++) {
            cin >> arr[j];
        }
        for(int j = 1; j < 11; j++) {
            for(int k = j; k < 11; k++) {
                for(int m = j; m <= k; m++) {
                    if(arr[m] <= arr[j-1] || arr[m] <= arr[k+1]) {
                        goto loop;
                    }
                }
                ans++;
loop: ;
            }
        }
        cout << i+1 << " " << ans << "\n";
    }
    return 0;
}

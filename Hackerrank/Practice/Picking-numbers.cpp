#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];
int n, ans;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int lo = 0, hi = 0;
    while(hi < n) {
        if((int)abs(arr[hi]-arr[lo]) > 1) {
            ans = max(ans,hi-lo);
            lo = hi;
        } else {
            ans = max(ans,hi-lo+1);
        }
        hi++;
    }
    cout << ans << "\n";
    return 0;
}

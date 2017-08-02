#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr1[100], arr2[100];
int lo = 1,hi;
int ans;

int lcm(int a,int b) {
    return (a*b)/__gcd(a,b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
      cin >> arr1[i];
      lo = lcm(lo,arr1[i]);
    }
    for(int i = 0; i < m; i++) {
      cin >> arr2[i];
      hi = __gcd(hi,arr2[i]);
    }
    for(int i = lo; i <= hi; i+=lo) {
        ans+=(hi % i == 0);
    }
    cout << ans << endl;
    return 0;
}

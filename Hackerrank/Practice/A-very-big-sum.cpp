#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; 
    scanf("%d",&n);
    int arr[n];
    long long ans = 0;
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
        ans += arr[arr_i];
    }
    cout << ans << endl;
    return 0;
}

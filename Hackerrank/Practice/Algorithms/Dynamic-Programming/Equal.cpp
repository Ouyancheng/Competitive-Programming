#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cc,n;
int arr[10000];
int min0;

int ops(int base) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = arr[i]-base;
        ans += (x/5) + (x%5)/2 + (x%5)%2; 
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> cc;
    for(int i = 0; i < cc; i++) {
        min0 = 1 << 30;
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
            min0 = min(min0,arr[j]);
        }
        cout << min(ops(min0),min(min(min(ops(min0-1),ops(min0-2)),ops(min0-3)),ops(min0-4))) << endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int mina = INT_MAX,minb = INT_MAX,min2a = INT_MAX,min2b = INT_MAX;
int n,a,ida,idb;
int arr[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a < mina) {
            min2a = mina;
            mina = a;
            ida = i;
        } else if(a < min2a) {
            min2a = a;
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a < minb) {
            min2b = minb;
            minb = a;
            idb = i;
        } else if(a < min2b) {
            min2b = a;
        }
    }
    if(ida != idb) {
        cout << mina + minb << "\n";
    } else {
        cout << min(mina+min2b,min2a+minb) << "\n";
    }
    return 0; 
}

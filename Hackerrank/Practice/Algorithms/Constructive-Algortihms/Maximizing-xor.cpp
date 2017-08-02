#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int L,R;
int ans;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> L >> R;
    int tmp = L ^ R; ans = 1;
    while(tmp) {
        tmp >>= 1;
        ans <<= 1;
    }
    cout << ans - 1 << endl;
    return 0;
}

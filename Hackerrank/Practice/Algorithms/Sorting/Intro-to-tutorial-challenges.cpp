#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,V,a;
    cin >> V >> N;
    for(int i = 0; i < N; i++) {
        cin >> a;
        if(a==V) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

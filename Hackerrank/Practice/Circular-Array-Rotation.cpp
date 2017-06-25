#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
        int n = 0, k, q, a[2*100000], t; 
        cin >> n >> k >> q;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i+n] = a[i];
        }
         for(int i = 0; i < q; i++) {
             cin >> t;
             cout << a[n-k%n+t] << endl;
        }       
    return 0;
}

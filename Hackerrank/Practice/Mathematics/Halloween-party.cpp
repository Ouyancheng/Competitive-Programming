#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int k;
    cin >> k;
    while(k-->=1) {
        long long c;
        cin >> c;
      cout << (c/2) * (c/2+c%2)<<endl;
          }
    return 0;
}

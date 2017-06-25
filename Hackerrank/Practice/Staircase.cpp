#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0; 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            cout << " ";
        }
        for(int j = n-i + 1; j <= n; j++) {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}

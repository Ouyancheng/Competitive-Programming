#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int m[1000][1000];
int n;
int sum1;
int sum2;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        sum1 += m[i][i];
        sum2 += m[i][n-i-1];
    }
    cout << abs(sum1-sum2) << "\n";
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
double n[110], dev;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    double t = 0; double mean = 0;
    cin >> N;
    cout.precision(1);
    cout << fixed;
    for(int i = 0; i < N; i++) {
        cin >> n[i];
        t += n[i];
    }
    mean = t/N;
    for(int i = 0; i < N; i++) {
        dev += (n[i] - mean)*(n[i] - mean);
    }
    cout << sqrt(dev/N) << endl;
    return 0;
}

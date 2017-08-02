#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int c;
long long n;

int isPrime(long long n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    
    if(n % 3 == 0 || n % 2 == 0)
        return false;
    
    for(long long i = 5; i*i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> n;
        if(isPrime(n)) {
            cout << "Prime" << "\n";
        } else {
            cout << "Not prime" << "\n";
        }
    }
    return 0;
}

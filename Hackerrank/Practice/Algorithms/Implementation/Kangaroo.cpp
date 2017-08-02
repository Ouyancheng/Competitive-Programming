#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x,a,y,b;
    cin >> x >> a >> y >> b;
    if(y == x) {
        cout << "YES" << "\n";
    } else if(y > x) {
        if(a <= b) {
            cout << "NO" << "\n";
        } else {
            if(!((y-x)%(a - b))) cout << "YES" << "\n";
            else cout << "NO" << endl;
        }
    } else {
        if(b <= a) {
            cout << "NO" << "\n";
        } else {
            if(!((x-y)%(b - a))) cout << "YES" << "\n";
            else cout << "NO" << endl;
        }
    }
    
    return 0;
}

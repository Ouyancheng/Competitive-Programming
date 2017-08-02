#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    int sw = 0;
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(a[j] > a[j+1]) {
                sw++;
                swap(a[j],a[j+1]);
            }
        }
    }
    cout << "Array is sorted in " << sw << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n-1] << endl;
  return 0;
}

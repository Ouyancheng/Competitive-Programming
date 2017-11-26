#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b,a%b) : a;
}

int d, a[1005], n;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n;
   
   for(int i = 0; i < n; i++) {
       cin >> a[i];
       if(i == 0) d = a[i];
       d = gcd(d,a[i]);
   }
   sort(a,a+n);
   if(d != a[0]) {
       cout << -1;
   } else {
       cout << 2*n << "\n";
       for(int i = 0; i < n; i++) {
           cout << a[i] << " " << a[0] << " ";
       }
   }
   cout << "\n";
   
   return 0;
}
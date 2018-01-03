#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n;

int ipow(int x, int y) {
  if(y == 0) {
    return 1;
  }
  int t = ipow(x, y/2);
  return y & 1 ? (1LL * x * t % mod) * t % mod : (1LL * t * t) % mod;
}

int main() {
  cin >> n;
  cout << (ipow(3, n*3) - ipow(7, n) + mod) % mod << "\n";
  return 0;
}
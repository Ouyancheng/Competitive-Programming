#include<iostream>

using namespace std;

int n, k, l, c, d, p, nl, np;

int main(void) {
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  cout << min((k*l)/nl,min(c*d,p/np))/n << endl;
  return 0;
}
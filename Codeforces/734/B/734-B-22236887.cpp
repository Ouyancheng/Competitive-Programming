#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
  int two,thr,fiv,six;

  cin >> two >> thr >> fiv >> six;
  long long sum = 0;

  int lo = min(two,min(six,fiv));
  six = fiv = (two -= lo);
  sum += lo * 256;
  lo = min(two,thr);
  sum += lo * 32;
  cout << sum << endl;
}
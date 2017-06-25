#include<set>
#include<iostream>

using namespace std;

set<int> s;
int a, b, c, d;

int main(void) {
  cin >> a >> b >> c >> d;
  s.insert(a);
  s.insert(b);
  s.insert(c);
  s.insert(d);
  cout << 4 - s.size() << endl;
  return 0;
}
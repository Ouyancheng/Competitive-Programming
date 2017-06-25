#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string a,b;

int main() {
  cin >> a >> b;
  transform(a.begin(),a.end(),a.begin(),::tolower);
  transform(b.begin(),b.end(),b.begin(),::tolower);
  if(a < b) {
    cout << -1 << endl;
  } else if(a > b) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
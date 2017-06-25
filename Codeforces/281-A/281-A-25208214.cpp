#include<iostream>
#include<string>

using namespace std;

string s;

int main(void) {
  cin >> s;
  if(s[0] >= 97 && s[0] <= 97 + 25) {
  	s[0] -= 32;
  }
  cout << s << endl;
  return 0;
}
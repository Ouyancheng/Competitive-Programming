#include<iostream>

using namespace std;

string s;
int luck;

int main() {
  cin >> s;
  for(int i = 0; i < s.length(); i++) {
    luck += (s[i] == '4' || s[i] == '7');
  }
  if(luck >= 10) {
    if((luck % 10 == 4 || luck % 10 == 7) && (luck/10 % 10 == 4 || luck/10 % 10 == 7)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if(luck % 10 == 4 || luck % 10 == 7) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
#include<iostream>
#include<string>

using namespace std;

int n;
string s;

int main(void) {
  cin >> n;
  while(n--) {
  	cin >> s;
    if(s.length() > 10) {
    	cout << s[0] + to_string(s.length()-2) + s[s.length()-1] << endl;
    } else {
    	cout << s << endl;
    }
  }
  return 0;
}
#include<iostream>
#include<string>
#include<set>

using namespace std;

string s;
set<char> u;

int main(void) {
  cin >> s;
  for(char c : s) {
    u.insert(c);
  }
  if(u.size() & 1) {
  	cout << "IGNORE HIM!" << endl;
  } else {
  	cout << "CHAT WITH HER!" << endl;
  }
  return 0;
}
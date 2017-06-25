#include<iostream>
#include<string>

using namespace std;

int c[4];

string s,ans;

int main(void) {
	cin >> s;
    for(int i = 0; i < s.length(); i+=2) {
    	c[s[i]-'0']++;
    }
    for(int i = 1; i <= 3; i++) {
      while(c[i]-- > 0) {
      	ans += to_string(i) + "+";
      }
    }
    cout << ans.substr(0,ans.length()-1) << endl;
    return 0;
}
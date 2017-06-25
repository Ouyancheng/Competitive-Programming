#include<iostream>

using namespace std;

string s;
int i;

int main(void) {
    cin >> s;
    while(i < s.length()) {
    	if(i < s.length() - 2) {
        	if(s[i] == '1' && s[i+1] == '4' && s[i+2] == '4') {
            	i += 3;
              	continue;
            }
        }
      	if(i < s.length() - 1) {
        	if(s[i] == '1' && s[i+1] == '4') {
              i += 2;
              continue;
            }
        }
        if(s[i] == '1') {
          i++;
        } else {
          cout << "NO" << endl;
          return 0;
        }
    }
    cout << "YES" << endl;
	return 0;
}
#include<iostream>

using namespace std;

string s;
int n;

int main(void) {
  	cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++) {
      if(i < n-1) {
        if(s[i] == '-' && s[i+1] == '-') {
        	cout << "2";
          	i++;
        } else if(s[i] == '-' && s[i+1] == '.') {
        	cout << "1";
            i++;
        } else {
        	cout << "0";
        }
      } else {
      	cout << "0";
      }
    }
  	cout << endl;
	return 0;
}
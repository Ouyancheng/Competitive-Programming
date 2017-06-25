#include<iostream>
#include<string>

using namespace std;

string s1,s2,s3;
int occ[26];
string s;

int main(void) {
  cin >> s1 >> s2 >> s3;
  for(char c : s3) {
  	occ[c-65]++;
  }
  for(char c : s1) {
    occ[c-65]--;
  }
  for(char c : s2) {
    occ[c-65]--;
  }
  for(int i = 0; i < 26; i++) {
  	if(occ[i] != 0) {
    	cout << "NO" << endl;
        return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
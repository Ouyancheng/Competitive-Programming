#include<iostream>

using namespace std;

int n;
string s;
string a;
char old;

int main(void) {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
    	if(s[i] != old) {
        	old = s[i];
            a += old;
        }
    }
    cout << n - a.length() << endl;
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s;
int lo,hi;

int main(void) {
    cin >> s;
    for(char c : s) {
    	if(c >= 97 && c <= 97 + 25) {
        	lo++;
        } else {
        	hi++;
        }
    }
    if(lo >= hi) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    } else {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    cout << s << endl;
	return 0;
}
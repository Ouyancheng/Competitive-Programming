#include<iostream>
#include<bitset>
#include<string>

using namespace std;

string a,b;

int main(void) {
    cin >> a >> b;
    bitset<100> x(a);
    bitset<100> y(b);
    string s = (x ^ y).to_string();
    for(int i = s.length() - a.length(); i < s.length(); i++) {
    	cout << s[i];
    }
    cout << endl;
	return 0;
}
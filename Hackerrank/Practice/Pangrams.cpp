#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long MAX = pow(2,26)-1;
    long val = 0;
    string s;
    getline(cin,s);
    for(int i = 0; i < s.length(); i++) {
        if(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') val |= 1 << (tolower(s[i])-'a');
    }
    cout << ((val == MAX) ? "pangram" : "not pangram") << endl;
    return 0;
}
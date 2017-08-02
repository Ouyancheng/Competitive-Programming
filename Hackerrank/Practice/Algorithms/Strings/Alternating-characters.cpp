#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sc = 0;
    cin >> sc;
    char c = '\0';
    while(sc-- >= 1) {
        string s;
        cin >> s;
        int i = 1, d = 0, con = 1;
        c = s[0];
        while(i < s.length()) {
            if(c != s[i]) {
                d += con - 1;
                con = 1;
                c = s[i];
            } else {
                con++;
            }
            i++;
        }
        if(con > 1) {
            d += con-1;
        }
        cout << d << endl;
    }
    return 0;
}

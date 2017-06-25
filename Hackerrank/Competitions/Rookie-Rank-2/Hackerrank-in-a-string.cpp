#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n;
    string t = "hackerrank";
    while(n--) {
        int ti = 0;
        cin >> s;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]==t[ti]) {
                ti++;
            }
        }
        if(ti == t.length()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}

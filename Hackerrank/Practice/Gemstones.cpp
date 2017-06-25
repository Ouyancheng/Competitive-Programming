#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int c = 0, u = (1 << 26)-1, cc = 0;
    string s;
    cin >> cc;
    for(int i = 0; i < cc; i++) {
        cin >> s;
        int c = 0;
        for(int j = 0; j < s.length(); j++) {
          c |= (1 << (s[j]-'a'));
        }
        u &= c;
    }
    int ans = 0;
    while(u) {
        ans++;
        u -= (u & -u);
    }
    cout << ans << endl;
    return 0;
}
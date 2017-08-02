#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
string s;

int main() {
    cin >> n >> s >> k;
    
    for(int i = 0; i < n; i++) {
        if(!(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 'a' && s[i] <= 'z')) {
            cout << s[i];
        } else if(s[i] >= 'A' && s[i] <= 'Z') {
            cout << (char) ((s[i]-'A' + k)%26+'A');
        } else {
            cout << (char) ((s[i]-'a' + k)%26+'a');
        }
    }
    cout << "\n";
    return 0;
}

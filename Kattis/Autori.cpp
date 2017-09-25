#include<iostream>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    cout << s[0];
    for(int i = 1; i < (int) s.length()-1; i++) {
        if(s[i] == '-') {
            cout << s[i+1];
            i++;
        }
    }
    cout << "\n";
    return 0;
}
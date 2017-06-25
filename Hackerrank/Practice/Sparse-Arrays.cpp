#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unordered_map<string,int> m;
    string s;
    int a = 0, b = 0;
    cin >> a;
    for(int i = 0; i < a; i++) {
        cin >> s;
        if(m.find(s) != m.end()) m[s]++;
        else m.insert(pair<string,int>(s,1));
    }
    cin >> b;
    for(int i = 0; i < b; i++) {
        cin >> s;
        cout << m[s] << endl;
    }
    return 0;
}

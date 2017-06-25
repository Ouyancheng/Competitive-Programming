#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a,b,n;
vector<int> v,m;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a == 1) {
            cin >> b;
            v.push_back(b);
            if(m.size())
                m.push_back(max(m.back(),b));
            else
                m.push_back(b);
        } else if(a == 2) {
            m.pop_back();
            v.pop_back();
        } else {
            cout << m.back() << "\n";
        }
    }
    return 0;
}

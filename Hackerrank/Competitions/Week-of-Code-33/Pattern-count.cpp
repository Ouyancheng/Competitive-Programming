#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ii pair<int,int>
#define fi first
#define se second
#define eb emplace_back

vector<ii> v;

int n;
string s;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int ans = 0;
        cin >> s;
        v.clear();
        for(int j = 0; j < (int)s.length(); j++) {
            if(s[j] == '0') {
                if(v.size() && v.back().fi == 1) {
                    v.eb(0,1);
                } else if(v.size()) {
                    v.back().se += 1;
                }
            } else if(s[j] == '1') {
                if(v.size() && v.back().fi == 0) {
                    ans++;
                }
                v.clear();
                v.eb(1,1);
            } else {
                v.clear();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

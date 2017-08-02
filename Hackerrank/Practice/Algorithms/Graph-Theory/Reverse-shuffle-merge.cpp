#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int cnt[26], rem[26];
string s;
char out[10005];
int n,sz,cur=-1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = (int) s.length();
    
    for(int i = 0; i < n; i++) {
        cnt[s[i]-'a'] = ++rem[s[i]-'a'];
    }
    for(int i = 0; i < 26; i++) {
        if(rem[i]) {
           rem[i] /= 2;
           sz += rem[i];
        }
    }
    reverse(s.begin(),s.end());
    
    int j = 0;
    for(int i = 0; i < sz; i++) {
        char best = '{';
        while(cnt[s[j]-'a'] > rem[s[j]-'a']) {
            cnt[s[j]-'a']--;
            j++;
        }
        int tmp;
        for(int k = j; k > cur; k--) {
            if(s[k] <= best && rem[s[k]-'a']) {
                best = min(best,s[k]);
                tmp = k;
            }
        }
        cur = tmp;
        cout << best;
        rem[best-'a']--;
    }
    cout << "\n";
    
    return 0;
}

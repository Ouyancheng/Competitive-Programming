#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef long long ll;
int n, k;
int letter[26];
string s;
vector< pair<int, char> > v;
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++) {
        letter[s[i]-'A']++;
    }
    for(int i = 0; i < 26; i++) {
        v.push_back(make_pair(letter[i],i+'A'));
    }
    sort(v.begin(),v.end(),greater< pair<int,char> >());
    for(int i = 0; i < (int) v.size(); i++) {
        if(k >= v[i].first) {
            k -= v[i].first;
            ans += 1LL* v[i].first * v[i].first;
        } else {
            ans += 1LL * k * k;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
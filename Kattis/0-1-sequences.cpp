#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;
 
ll pow2[500001];
 
void genpows() {
    int num = 1;
    for(int i = 0; i<= 500000;i++) {
        pow2[i] = num;
        num*= 2;
        num = num%MOD;
    }
}
 
int solve(int x) {
    ll ans = x;
    ans*= x-1;
    ans/= 2;
    ans = ans%MOD;
    ans*= pow2[x-2];
    ans = ans%MOD;
    return ans;
}
 
int ways(int x) {
    ll ans = x;
    ans*= pow2[x-1];
    return ans%MOD;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    genpows();
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 0;
    vector<int> cnt1till (n,0);
    vector<int> cntqtill (n,0);
    cnt1till[0] = (s.at(0) == '1' ? 1 : 0);
    cntqtill[0] = (s.at(0) == '?' ? 1 : 0);
    for(int i = 1; i < n; i++) {
        cnt1till[i] = cnt1till[i-1]; // stores count of 1 until i exclusive
        cntqtill[i] = cntqtill[i-1]; // stores count of ? until i exclusive
        if(s.at(i) == '1') {
            cnt1till[i]++;
        } else if(s.at(i) == '?') {
            cntqtill[i]++;
        }
    }
    int allq = cntqtill[n-1]; // stores number of ? in the string
    for(int i = 0; i < n; i++) {
        if(s.at(i) == '0') {
            ans+= (cnt1till[i])*pow2[allq]%MOD; // stores number of inversions created by known and known
            ans+= ways(cntqtill[i])*pow2[allq-cntqtill[i]]%MOD; // stores number of inversions created by known and ?
            ans = ans%MOD;
        } else if(s.at(i) == '1') {
            ans+= ways(allq-cntqtill[i])*pow2[cntqtill[i]]%MOD; // stores number of inversions created by known and ?
            ans = ans%MOD;
        }
    }
    ans+= solve(allq)%MOD;
    cout << ans%MOD;
    return 0;
}
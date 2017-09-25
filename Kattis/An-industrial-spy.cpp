#include<bits/stdc++.h>

using namespace std;

#define setbit(x,a) (a[x>>6])|=(1<<((x>>1)&31))
#define chkbit(x,a) (a[x>>6])&(1<<((x>>1)&31))
#define isprime(x) (!(x!=2&&(!(x&1)||chkbit(x,prime)))) // this macro is used for sieve(n) only!

const int MAX_N = 1e7;

int n,v[MAX_N];
unsigned int prime[MAX_N/64+1];
string s;
vector<string> com;
vector<int> tot;

void sieve(int n) {
    setbit(1,prime);
    for(int i = 3; i*i <= n; i+=2) {
        if(chkbit(i,prime)) continue;
        for(int j = i*i, k = i<<1; j <= n; j+=k) {
            setbit(j,prime);
        }
    }
}

void sets(string &s) {
    int n = (int) s.length();
    for(int i = 1; i < (1 << n); i++) {
        string num = "";
        for(int j = n-1; j >= 0; j--) {
            if(i & (1 << j)) {
                num += to_string(s[j] - '0');
            }
        }
        com.push_back(num);
    }
}

void perm() {
    for(int i = 0; i < (int) com.size(); i++) {
        do {
            int a = stoi(com[i]);
            if(!v[a]) {
                tot.push_back(a);
                v[a] = 1;
            }
        } while(next_permutation(com[i].begin(),com[i].end()));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    sieve(MAX_N);
    while(n--) {
        long long ans = 0;
        cin >> s;
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        com.clear();
        tot.clear();
        sets(s);
        perm();
        for(auto p : tot) {
            ans += isprime(p);
            v[p] = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}

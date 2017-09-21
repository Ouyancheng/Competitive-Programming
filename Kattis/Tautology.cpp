#include<bits/stdc++.h>

using namespace std;

string s;
int mask[32];
bool pc[5];

bool proc(char c,bool a,bool b) {
    assert(c == 'K' || c == 'A' || c == 'C' || c == 'E');
    if(c == 'K') {
        return a & b;
    } else if(c == 'A') {
        return a | b;
    } else if(c == 'C') {
        return (!a) | b;
    }
    return a == b;
}

bool act(char c,int t) {
    assert(c >= 'p' && c <= 't');
    return mask[t] & (1 << (c-'p'));
}

bool f(int t) {
    int n = (int) s.length();
    stack<bool> val;
    for(int i = n-1; i >= 0; i--) {
        char c = s[i];
        if(c >= 'p' && c <= 't') {
            val.push(act(c,t));
        } else {
            if(c == 'N') {
                assert(!val.empty());
                bool tmp = val.top();
                val.pop();
                val.push(!tmp);
            } else {
                assert(val.size() >= 2);
                bool tmp1 = val.top();
                val.pop();
                bool tmp2 = val.top();
                val.pop();
                val.push(proc(c,tmp1,tmp2));
            }
        }
    }
    assert(val.size() == 1);
    return val.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 32; i++) mask[i] = i;
    while(cin >> s) {
        if(s == "0") break;
        memset(pc,0,sizeof pc);
        bool ans = 1;
        for(int i = 0; i < (int) s.length(); i++) {
            if(s[i] >= 'p' && s[i] <= 't') {
                pc[s[i]-'p'] = 1;
            }
        }
        for(int i = 0; i < 32 && ans; i++) {
            ans &= f(i);
        }
        if(ans) {
            cout << "tautology";    
        } else {
            cout << "not";
        }
        cout << "\n";
    }
    return 0;
}
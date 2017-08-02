#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

typedef pair <char,int> pii;

int main() {
    unordered_map <int,int> um;
    string s;
    cin>>s;
    
    int flag = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(um.find(s[i])==um.end()) um.insert(pii(s[i],1));
        else um[s[i]]++;
    }
    
    for(auto p : um) if(p.second%2) flag++;
    
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    if(flag > 1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ll s,p1[100000+1],p2[100000+1];
    set<int> u;
    cin>>N;
    while(N--) {
      string ans= "NO";
      cin >> s;
      for(int i = 1; i <= s; ++i) {
          cin >> p1[i];
          p2[i]=p1[i];
      }
        p1[0] = p2[0] = 0;
        p1[s+1] = p2[s+1] = 0;
        s+=2;
        for(int i=0; i < s-2; ++i) {
            p1[i+1] += p1[i];
            p2[s-2-i]+=p2[s-1-i];
        }
        for(int i = 1; i < s-1; ++i) {
            if(p1[i-1]==p2[i+1]) {
                ans="YES";
                break;
            }
        }   
      cout<<ans<<"\n";
    }
    return 0;
}

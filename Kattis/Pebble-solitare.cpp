#include <bits/stdc++.h>

using namespace std;

int t;
char a[12];
int ans = 13;

void go(int x,int y,int z,char c1,char c2,char c3) {
    a[x] = c1, a[y] = c2, a[z] = c3;
}

bool can(int i) {
    return i >= 0 && i < 12;
}

void dfs(int c) {
    for(int u = 0; u < 12; u++) {
        if(a[u] == '-') continue;
        if(can(u-1) && can(u+1) && a[u-1] == 'o' && a[u+1] == '-') {
            go(u-1,u,u+1,'-','-','o');
            dfs(c-1);
            go(u-1,u,u+1,'o','o','-');
        } else if(can(u-1) && can(u+1) && a[u-1] == '-' && a[u+1] == 'o') {
            go(u-1,u,u+1,'o','-','-');
            dfs(c-1);
            go(u-1,u,u+1,'-','o','o');
        }   
    }
    ans = min(ans,c);
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> t;
   while(t--) {
       ans = 13; int c = 0;
       for(int i = 0; i < 12; i++) {
           cin >> a[i];
           if(a[i] == 'o') {
               c++;
           }
       }
       dfs(c);
       cout << ans << "\n";   
   }
   return 0;
}
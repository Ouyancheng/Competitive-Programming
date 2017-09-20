#include <bits/stdc++.h>

using namespace std;

int n,m,bi = -1,bj = -1;
char a[55][55];
int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool val(int i,int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int calc(int i,int j) {
    int ans = 0;
    for(int ii = 0; ii < 8; ii++) {
        if(val(i+dr[ii],j+dc[ii]) && a[i+dr[ii]][j+dc[ii]] == 'o') {
            ans++;
        }
    }
    return ans;
}

void best() {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '.') {
                int tmp = calc(i,j);
                if(tmp > ans) {
                    bi = i;
                    bj = j;
                    ans = tmp;
                }
            }
        }
    }
}

long long f() {
    long long ans = 0;
    best();
    if(bi != -1 && bj != -1) a[bi][bj] = 'o';
    //cout << "value of bi is " << bi << "\n";
    //cout << "value of bj is " << bj << "\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'o') {
                ans += calc(i,j);
                a[i][j] = '.';
            }
        }
    }
    return ans;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n >> m;
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {
           cin >> a[i][j];
           //cout << a[i][j] << " ";
       }
       //cout << "\n";
   }
   cout << f() << "\n";
   return 0;
}

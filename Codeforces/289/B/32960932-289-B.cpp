#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int mat[105][105];
int n, m, d, base = 100000;

bool chk() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int x = i; x < n; x++) {
                for(int y = j; y < m; y++) {
                    if(i == x && j == y) {
                        continue;
                    } else if((int)abs(mat[i][j]-mat[x][y]) % d != 0) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int val(int g) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += (int)abs(mat[i][j]-g);
        }
    }
    return ans/d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            base = min(base,mat[i][j]);
        }
    }
    if(chk()) {
        int lo = 0, hi = 10000/d, ansv = 300000000;
        for(int i = 0; i < 60 && lo < hi; i++) {
            int li = lo + (hi - lo)/3, ri = hi - (hi - lo)/3;
            int lval = val(base+li*d), rval = val(base+ri*d);
            if(lval <= rval) {
                hi = ri;
            } else {
                lo = li;
            }
        }
        for(int i = lo; i <= hi; i++) {
            ansv = min(ansv,val(base+i*d));
        }
        cout << ansv;
    } else {
        cout << -1;
    }
    cout << "\n";
    return 0;
}
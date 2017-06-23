#include <iostream>
#include <algorithm>
using namespace std;

int sum[160][80];
int cc,r,c,R,C,INF = 999999999;
int ans,tmax,gmax,srow,amax,asum;

void f(int mat[80][80]) {
    for(int i = 1; i < r+1; i++) {
            for(int j = i; j < i+r; j++) {
                amax = -INF, asum = 0, tmax = 0; gmax = -INF;
                for(int m = 0; m < c; m++) {
                    amax = max(amax,mat[j][m]-mat[i-1][m]);
                }
                if(amax >= 0) {
                    for(int m = 0; m < c; m++) {
                        srow = mat[j][m]-mat[i-1][m];
                        asum += srow;
                        tmax = max(-srow,tmax+(-srow));
                        gmax = max(tmax,gmax);
                    }
                    ans = max(ans,asum+gmax);
                    amax = -INF, tmax = 0; gmax = -INF;
                    for(int m = 0; m < c; m++) {
                        srow = mat[j][m]-mat[i-1][m];
                        tmax = max(srow,tmax+srow);
                        gmax = max(tmax,gmax);
                    }
                    ans = max(ans,gmax);
                } else {
                    ans = max(ans,amax);
                }
            }
        }    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> cc;
    while(cc--) {
        cin >> r;
        c = r;
        ans = -INF;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> sum[i+1][j];
                sum[i+r+1][j] = sum[i+1][j];
            }
        }
        for(int i = 0; i < 2*r; i++) {
            for(int j = 0; j < c; j++) {
                sum[i+1][j] += sum[i][j];
            }
        }
        f(sum);
        cout << ans << endl;
    }
    return 0;
}
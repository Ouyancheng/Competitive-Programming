#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define max(a,b,c) max(a,max(b,c))
#define bound 245
#define furthest 30000

int dp[furthest+1][491];
int gem[furthest+1];
int n, d, a, ans, offset;

int f(int cur,int jump) {
    if(cur > furthest || jump <= 0) return 0;
    if(dp[cur][jump-offset] > -1) return dp[cur][jump-offset];
    return dp[cur][jump-offset] = gem[cur] + max(f(cur+jump-1,jump-1),f(cur+jump,jump),f(cur+jump+1,jump+1));
}

int main() {
    scanf("%d %d",&n,&d);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a);
        gem[a]++;
    }
    for(int i = 0; i < furthest+1; i++) {
        for(int j = 0; j < 491; j++) {
            dp[i][j] = -1;
        }
    }
    offset = d - bound;
    ans = f(d,d);
    printf("%d\n", ans);
    return 0;
}
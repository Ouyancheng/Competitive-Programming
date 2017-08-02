#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lcs[5001][5001];
char s1[5001], s2[5001];
int n;

int main() {
    scanf("%s %s",s1,s2);
    int n = strlen(s1);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];
            } else {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    printf("%d\n",lcs[n][n]);
    return 0;
}

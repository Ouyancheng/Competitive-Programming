#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mat[105][105], is[105][105];
int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            mat[i][j] = s[j]-'0';
        }
    }
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < n-1; j++) {
            if(mat[i][j+1] < mat[i][j] && mat[i][j-1] < mat[i][j] &&
              mat[i-1][j] < mat[i][j] && mat[i+1][j] < mat[i][j]) {
                is[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(is[i][j]) cout << 'X';
            else cout << mat[i][j];
        }
        cout << "\n";
    }
    return 0;
}

#include<iostream>

using namespace std;

#define MAX_N 100

string dp[MAX_N][MAX_N];
int a1[MAX_N],a2[MAX_N];
int n,m;

string lcs(int i,int j,int a1[],int a2[]) {
    if(i == n || j == m) return "";
    if(dp[i][j] != "") return dp[i][j];
    if(a1[i] == a2[j]) return dp[i][j] = to_string(a1[i])+" "+lcs(i+1,j+1,a1,a2)+" ";
    else {
        string res1 = lcs(i+1,j,a1,a2);
        string res2 = lcs(i,j+1,a1,a2);
        if((int)res1.length() > (int)res2.length()) {
            return dp[i][j] = res1;
        } else {
            return dp[i][j] = res2;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a1[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> a2[i];
    }
    cout << lcs(0,0,a1,a2) << "\n";
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T, K, N;
int used[100005];
int out[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> N >> K;
        fill(used,used+N+1,0);
        fill(out,out+N+1,0);
        int flag = 0;
        for(int i = 1; i <= N; i++) {
            if(i-K > 0 && !used[i-K]) {
                out[i] = i-K;
                used[i-K] = 1;
            } else if(i+K <= N && !used[i+K]) {
                out[i] = i+K;
                used[i+K] = 1;
            } else {
                cout << -1;
                flag = 1;
                break;
            }
        }
        if(!flag) {
            for(int i = 1; i <= N; i++) {
                cout << out[i] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

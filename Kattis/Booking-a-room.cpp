#include<iostream>

using namespace std;

bool u[105];
int a,n,k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    if(n == k) {
        cout << "too late" << "\n";
        return 0;
    }
    for(int i = 0; i < k; i++) {
        cin >> a;
        u[--a] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(!u[i]) {
            cout << i+1 << "\n";
            return 0;
        }
    }
}
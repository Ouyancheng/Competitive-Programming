#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];
int n,t;

void place(int i,int j,int k,int d) {
    while(arr[i] != d) {
        swap(arr[i],arr[j]);
        swap(arr[i],arr[k]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++) {
            int start = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] == i+1) {
                    start = j;
                    break;
                }
            }
            for(int j = min(n-3,start); j >= i; j--) {
                place(j,j+1,j+2,i+1);
            }
        }
        if(is_sorted(arr,arr+n)) {
            cout << "YES";
        } else {
                cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}

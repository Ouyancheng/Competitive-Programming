#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, n[60], iqr[100000], M;

double med(int a[],int lo,int hi) {
    int z = hi-lo+1, mid = (z-1)/2;
    if(z&1) {
        return (a[lo+mid]);
    } else {
        return (a[lo+mid] + a[lo+mid+1])/2.0;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout.precision(1);
    cout << fixed;
    int iqri = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> n[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> M;
        for(int j = 0; j < M; j++) {
            iqr[iqri++] = n[i];
        }
    }
    N = iqri;
    sort(iqr,iqr+N);
    int mid = (N-1)/2;
    if(N&1) {
        cout << med(iqr,mid+1,N-1) - med(iqr,0,mid-1) << endl;
    } else {
        cout << med(iqr,mid+1,N-1) - med(iqr,0,mid) << endl;
    }
    
    return 0;
}

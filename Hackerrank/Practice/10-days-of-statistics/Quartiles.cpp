#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, n[60];

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
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> n[i];
    }
    sort(n,n+N);
    int mid = (N-1)/2;
    if(N&1) {
        cout << med(n,0,mid-1) << endl;
        cout << med(n,0,N-1) << endl;
        cout << med(n,mid+1,N-1) << endl;
    } else {
        cout << med(n,0,mid) << endl;
        cout << med(n,0,N-1) << endl;
        cout << med(n,mid+1,N-1) << endl;    
    }
    
    return 0;
}

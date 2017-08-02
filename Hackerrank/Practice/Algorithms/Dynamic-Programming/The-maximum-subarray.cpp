#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f1(int arr[],int n) {
    int maxE = -99999999, tmp = -99999999;
    for(int i = 0; i < n; i++) {
        tmp = max(arr[i],tmp+arr[i]);
        maxE = max(maxE,tmp);
    }
    return maxE;
}

int f2(int arr[],int n) {
    sort(arr,arr+n);
    int i = n-1;
    int maxE = 0;
    while(arr[i]>0) {
        maxE += arr[i--];
    }
    if(maxE == 0) maxE = arr[n-1];
    return maxE;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int cc = 0, n = 0;
    cin >> cc;
    while(cc-- >= 1) {
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int a = f1(arr,n), b = f2(arr,n);
        cout << a << " " << b << endl;
    }
    return 0;
}

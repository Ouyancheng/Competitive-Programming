#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, c[100010],mc,mn,n[100010];
double t;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    cout.precision(1);
    cout << fixed;
    for(int i = 0; i < N; i++) {
        cin >> n[i];
        t += n[i];
        c[n[i]]++;
    }
    cout << t/N << endl;
    sort(n,n+N);
    for(int i = 0; i < N; i++) {
        if(c[n[i]] > mc) {
            mn = n[i];
            mc = c[n[i]];
        }
    }
    if(N&1) {
        cout << n[N/2] << endl;
    } else {
        cout << (n[N/2] + n[N/2-1])/2.0 << endl;
    }
    cout << mn << endl;
    return 0;
}
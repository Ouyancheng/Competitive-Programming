#include<iostream>

using namespace std;

int n;
int a,b;
int lo,ho;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a >> b;
        if(a == 0) lo++;
        if(b == 0) ho++;
    }
    cout << min(lo,n-lo) + min(ho,n-ho) << endl;
	return 0;
}
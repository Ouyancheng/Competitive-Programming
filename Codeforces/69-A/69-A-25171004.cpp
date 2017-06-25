#include<iostream>

using namespace std;

int n,x,y,z;
int a,b,c;

int main(void) {
    cin >> n;
  	for(int i = 0; i < n; i++) {
    	cin >> x >> y >> z;
        a += x, b += y, c += z;
    }
    if(a | b | c) {
    	cout << "NO" << endl;
    } else {
    	cout << "YES" << endl;
    }
	return 0;
}
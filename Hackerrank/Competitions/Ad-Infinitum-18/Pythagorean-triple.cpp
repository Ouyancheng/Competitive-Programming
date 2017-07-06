#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    cout << a << " ";
	a = a * a;
	if(a&1) {
		cout << (a-1)/2 << " " << (a+1)/2;
	} else {
		cout << (a/4)-1 << " " << (a/4)+1;
	}
    cout << "\n";
    return 0;
}

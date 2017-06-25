#include<iostream>
#include<iomanip>

using namespace std;

int n;
double t,sum;

int main(void) {
	cin >> n;
    cout << setprecision(12);
    cout << fixed;
    for(int i = 0; i < n; i++) {
        cin >> t;
    	sum += t;
    }
    cout << sum/n << endl;
	return 0;
}
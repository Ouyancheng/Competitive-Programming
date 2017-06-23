#include<iostream>
#include<cmath>

using namespace std;

int n[20], T;
double res,lo,hi,mid;

double f(double a) {
	double ans = 0;
	for(int i = 0; i <= T; i++) {
		ans += n[i]/pow(1+a,i);
	}
	return ans;
}

int main(void) {
	cout.precision(2);
	cout << fixed;
	while(cin >> T, T) {
		for(int i = 0; i <= T; i++) {
			cin >> n[i];
		}
		hi = 1000000.00, lo = -0.999999999999;
		while(hi - lo >= 0.00000000001) {
			mid = (hi+lo)/2, res = f(mid);
			if(res < 0) {
				hi = mid - 0.00000000000001;
			} else {
				lo = mid + 0.00000000000001;
			}
		}
		cout << mid << endl;
	}
	return 0;
}
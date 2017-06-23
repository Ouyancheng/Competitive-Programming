#include<iostream>
#include<iomanip>

using namespace std;

int n, calc;
string ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << "PERFECTION OUTPUT" << endl;
	while(cin >> n, n) {
		calc = 0;
		for(int i = 1; i < n; i++) {
			if(n % i == 0) {
				calc += i;
			}
		}
		if(calc == n) {
			ans = "PERFECT";
		} else if(calc < n) {
			ans = "DEFICIENT";
		} else {
			ans = "ABUNDANT";
		}
		cout << std::setw(5) << std::right << n;
		cout << "  " << ans << "\n"; 
	}
	cout << "END OF OUTPUT" << "\n";
	return 0;
}
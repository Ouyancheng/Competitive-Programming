#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
int t;
double r, b, m;

void work() {
	double bal = b;

	for(int i = 0; i <= 1200; i++) {
		if(i > 0) {
			if(fabs(m - bal) < eps || m - bal >= eps) {
				cout << i << "\n";
				return;
			} else {
				bal = fmax(0.00, bal - m);
			}
		}
		bal += round(r * bal * 100 + eps) / 100;
	}
	cout << "impossible" << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> r >> b >> m;
		r = r / 100;
		work();
	}
	return 0;
}
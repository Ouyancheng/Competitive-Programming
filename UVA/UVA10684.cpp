#include<bits/stdc++.h>

using namespace std;

const int oo = 1e9;
int n, a, gmax, tmax;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n, n) {
		gmax = -oo, tmax = 0;
		while(n--) {
			cin >> a;
			tmax = max(tmax + a, a);
			gmax = max(gmax, tmax);
		}
		cout << ((gmax > 0) ? "The maximum winning streak is " + to_string(gmax) + "." : "Losing streak.") << "\n";
	}
}

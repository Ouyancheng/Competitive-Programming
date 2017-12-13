#include<iostream>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn = 1e6 + 5;
int n, a, b;
int wa, wb;
char out[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a >> b;
		if(abs(wa + a - wb) <= 500) {
			out[i] = 'A';
			wa += a;
		} else if(abs(wb + b - wa) <= 500) {
			out[i] = 'G';
			wb += b;
		} else {
			cout << -1 << "\n";;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << out[i];
	}
	cout << "\n";
	return 0;
}


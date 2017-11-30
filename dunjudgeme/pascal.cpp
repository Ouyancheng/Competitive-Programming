#include<iostream>

using namespace std;

int n, k;
long long nck[2][30];

void pre() {
	for(int i = 0; i <= n; i++) {
		int t = i & 1;
		for(int j = 0; j <= n; j++) {
			if(j == 0) {
				nck[t][j] = 1;
				continue;
			}
			nck[t][j] = nck[t^1][j] + nck[t^1][j-1];
		}
	}
}

int main() {
	cin >> n >> k;
	n--, k--;
	pre();
	cout << nck[n&1][k] << "\n";
	return 0;
}
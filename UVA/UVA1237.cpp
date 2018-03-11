#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;
int n1, n2, p, t, R[maxn], L[maxn];
string S[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n1;
		for(int i = 0; i < n1; i++) {
			cin >> S[i] >> L[i] >> R[i];
		}
		cin >> n2;
		for(int i = 0; i < n2; i++) {
			cin >> p;
			int count = 0, car = -1;
			for(int j = 0; j < n1; j++) {
				if(p >= L[j] && p <= R[j]) {
					count++;
					car = j;
					if(count > 1) {
						break;
					}
				}
			}
			if(count == 1) {
				cout << S[car];
			} else {
				cout << "UNDETERMINED";
			}
			cout << "\n";
		}
		if(t) {
			cout << "\n";
		}
	}
	return 0;
}
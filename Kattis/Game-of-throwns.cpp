#include<bits/stdc++.h>

using namespace std;

int n, k, c, d;
stack<int> S;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	c = 0;
	for(int i = 0; i < k; i++) {
		cin >> s;
		if(s == "undo") {
			cin >> d;
			while(d--) {
				c = S.top();
				S.pop();
			}
		} else {
			S.push(c);
			d = stoi(s);
			if(d < 0) {
				c = (c + 10000 * n + d) % n;
			} else {
				c = (c + d) % n;
			}
		}
	}
	cout << c << "\n";

}

#include<bits/stdc++.h>

using namespace std;

int n, a, b, x, y, z;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> ws) {
		stack<int> S;
		queue<int> Q;
		priority_queue<int> PQ;
		int cs = 0, cq = 0, cpq = 0, cnt = 0;
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			if(a == 1) {
				S.push(b);
				Q.push(b);
				PQ.push(b);
			} else {
				x = y = z = 0;
				cnt++;

				if((int) S.size() > 0) {
					x = S.top();
					S.pop();
				}
				if((int) Q.size() > 0) {
					y = Q.front();
					Q.pop();
				}
				if((int) PQ.size() > 0) {
					z = PQ.top();
					PQ.pop();
				}
				
				cs += (x == b);
				cq += (y == b);
				cpq += (z == b);
			}
		}

		if(cs == cnt) {
			if(cq == cnt || cpq == cnt) {
				cout << "not sure\n";
			} else {
				cout << "stack\n";
			}
		} else if(cq == cnt) {
			if(cpq == cnt) {
				cout << "not sure\n";
			} else {
				cout << "queue\n";
			}
		} else if(cpq == cnt) {
			cout << "priority queue\n";
		} else {
			cout << "impossible\n";
		}
	}
	return 0;
}
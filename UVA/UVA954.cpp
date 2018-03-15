#include<bits/stdc++.h>

using namespace std;

int n, a;
priority_queue<long long> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n, n) {
		long long sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> a;
			pq.push(-a);
		}
		while((int) pq.size() > 1) {
			int a = abs(pq.top());
			pq.pop();
			int b = abs(pq.top());
			pq.pop();
			pq.push(-(a+b));
			sum += a+b;
		}
		while((int) pq.size() > 0) pq.pop();
		cout << sum << "\n";
	}
}

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int n, a;
queue<int> in, out;
stack<int> mid;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(1) {
		cin >> n;
		if(!n) break;
		while(1) {
			cin >> a;
			if(!a) break;
			while(in.size() > 0) in.pop();
			while(out.size() > 0) out.pop();
			while(mid.size() > 0) mid.pop();
			for(int i = 1; i <= n; i++)
				in.push(i);

			out.push(a);
			for(int i = 1; i < n; i++) {
				cin >> a;
				out.push(a);
			}

			while(in.size() > 0) {
				int cur = in.front();
				in.pop();
				if(cur == out.front()) {
					out.pop();
					while(mid.size() > 0 && mid.top() == out.front()) {
						mid.pop(); out.pop();
					}
				} else {
					mid.push(cur);
				}
			}
			if(mid.size() == 0) {
				cout << "Yes" << "\n";
			} else {
				cout << "No" << "\n";
			}
		}
		cout << "\n";
	}
	return 0;
}
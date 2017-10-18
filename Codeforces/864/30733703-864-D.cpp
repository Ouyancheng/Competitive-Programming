#include<bits/stdc++.h>

using namespace std;

const int MAX_N = (int)2e5+5;
int n,x,a[MAX_N],c[MAX_N],v[MAX_N];
queue<int> rem;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	for(int i = 1; i <= n; i++) {
		if(c[i] == 0) rem.push(i);
	}
	for(int i = 1; i <= n && rem.size() > 0; i++) {
		if(c[a[i]] > 1) {
			//cout << "the duplicate is " << a[i] << endl;
			if(v[a[i]] || rem.front() < a[i]) {
				c[a[i]]--;
				a[i] = rem.front();
				rem.pop();
				x++;
			} else {
				v[a[i]] = 1;
			}
		}
	}
	cout << x << "\n";
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
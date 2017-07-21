#include<bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int df[MAX_N], ds[MAX_N];
int n,a,b,p1,p2;
vector<int> v[MAX_N];
queue<int> q;

void calc(int from,int to,int d[]) {
	fill(d+1,d+n+1,INT_MAX);
	q.emplace(from);
	d[from] = 0;
	while((int)q.size()) {
		int cur = q.front();
		q.pop();
		for(auto p : v[cur]) {
			if(p != to && d[p] == INT_MAX) {
				q.emplace(p);
				d[p] = d[cur]+1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	calc(1,n,df);
	calc(n,1,ds);

	for(int i = 1; i <= n; i++) {
		if(i == 1 || i == n) continue;
		if(df[i] <= ds[i]) p1++;
		else p2++;
	}
	if(p1 > p2) {
		cout << "Fennec";
	} else {
		cout << "Snuke";
	}
	cout << "\n";
	return 0;
}
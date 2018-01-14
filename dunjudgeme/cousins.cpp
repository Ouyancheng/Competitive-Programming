#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll ans;
string s;
unordered_map<string, int> M; 

ll ap(int n) {
	return (1LL * n * (n-1)) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		sort(s.begin(), s.end());
		M[s]++;
	}
	for(auto p : M) {
		ans += ap(p.second);
	}
	cout << ans << "\n";
	return 0;
}
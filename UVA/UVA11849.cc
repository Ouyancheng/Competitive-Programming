#include<iostream>
#include<unordered_set>


using namespace std;

int n,m,a;
unordered_set<int> u;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m, n && m) {
		u.clear();
		int ans = 0;
		for(int i = 0; i < n; i++) {
			cin >> a;
			u.insert(a);
		}
		for(int i = 0; i < m; i++) {
			cin >> a;
			if(u.find(a) != u.end()) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

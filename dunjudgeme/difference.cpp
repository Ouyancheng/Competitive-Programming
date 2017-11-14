#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int,long long> m;

int n,k,d;
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	m.reserve(2<<20);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> d;
		if(m.count(k+d) > 0) {
			ans += m[k+d];
		}
		if(m.count(d-k) > 0) {
			ans += m[d-k];
		}
		m[d]++;
	}
	cout << ans << "\n";
	return 0;
}

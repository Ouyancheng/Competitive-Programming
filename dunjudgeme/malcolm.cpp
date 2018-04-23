#include<bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
int n, k, a[maxn];
vector<int> sv[21];
string s;
long long ans;

int sum(int i, int vi) {
	auto p1 = lower_bound(sv[vi].begin(), sv[vi].end(), i + 1);
	if(p1 == sv[vi].end()) {
		return 0;
	}
	auto p2 = upper_bound(sv[vi].begin(), sv[vi].end(), i + k);
	p2--;
	return p2 - p1 + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> s;
		sv[(int) s.length()].push_back(i);
		a[i] = (int) s.length();
	}
	for_each(sv, sv + 21, [](auto p){ sort(p.begin(), p.end()); });
	for(int i = 0; i < n; i++) {
		int val = sum(i, a[i]);
		ans += val;
	}
	cout << ans << endl;
	return 0;
}
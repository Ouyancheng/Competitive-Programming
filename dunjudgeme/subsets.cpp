#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n, a[maxn];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < (1 << n); i++) {
		int tmp = 0;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				tmp += a[j];
			}
		}
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < (int) v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}

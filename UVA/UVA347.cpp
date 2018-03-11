#include<bits/stdc++.h>

using namespace std;

vector<int> v;

bool chk(vector<int> &v) {
	int u = 0, p = 0;
	bool yes[10];
	
	memset(yes, 0, sizeof yes);

	while(u < (int) v.size()) {
		if(yes[p] && p) return 0;
		yes[p] = 1;
		p = (p + v[p]) % (int) v.size();
		u++;
	}
	for(int i = 0; i < (int) v.size(); i++) {
		if(!yes[i]) return 0;
	}
	return p == 0;
}

int get(vector<int> &v) {
	int ans = 0;
	for(int i = (int) v.size()-1, exp = 1; i >= 0; i--, exp *= 10) {
		ans += v[i] * exp;
	}
	return ans;
}

void gen() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> tmp;
	for(int i = 0; i < (1 << 9); i++) {
		tmp.clear();
		for(int j = 0; (1<<j) <= i; j++) {
			if(i & (1<<j)) {
				tmp.push_back(a[j]);
			}
		}
		do {
			if(chk(tmp)) v.push_back(get(tmp));
		} while(next_permutation(tmp.begin(), tmp.end()));
	}
	sort(v.begin(), v.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 0, n = 0;
	gen();

	while(cin >> n, n) {
		cout << "Case " << ++t << ": ";
		cout << *lower_bound(v.begin(), v.end(), n) << "\n";
	}
	return 0;
}

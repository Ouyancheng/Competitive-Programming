#include<bits/stdc++.h>

using namespace std;

int n, ans = 0;
int dat[1000002];

// Factors numbers into their prime factors in O(sqrt(n))
vector<int> factor(int n) {
	int t = n;
	vector<int> factors;
	if(n == 0) return factors;
	for(int i = 2; 1LL*i*i <= n && t > 1; i++) {
		if(t % i == 0) {
			factors.push_back(i);
		}
		while(t % i == 0) {
			dat[i]++;
			t /= i;
		}
	}
	if(t > 1) {
		dat[t]++;
		factors.push_back(t);
	}
	return factors;
}


int main() {
	freopen("fractorial.in","r",stdin);
	freopen("fractorial.out","w",stdout);
	cin >> n;
	if(n == 1) {
		cout << 1;
	} else {
		vector<int> factors = factor(n);
		for(int i = 0; i < (int) factors.size(); i++) {
			int num = dat[factors[i]];
			int mul = 1, cur = 0;
			int np = factors[i], rep = 1;
			while(num > 0) {
				cur = mul++ * factors[i];
				if(cur == np) {
					num -= rep;
					np = np * factors[i];
					rep++;
				} else {
					num -= 1;
				}
			}
			ans = max(ans,cur);
		}
		cout << ans;
	}
	cout << "\n";

	return 0;
}

#include<iostream>
#include<unordered_set>

using namespace std;

#define FACTOR_LIM 1000005 // used by preFactor(n). Defined as <= n <= 1e8

int lowestDiv[FACTOR_LIM+1];
int n;
unordered_set<int> u;

// Pre-computes lowest divisors in O(sqrt(n)*loglogn) for fast factorization method
// This method requires O(n) space
void preFactor(int n) {
	int root = 2;
	for(int i = 2; i*i <= n; i++) {
		if(lowestDiv[i]) continue;
		root = lowestDiv[i] = i;
		for(int j = i*i; j <= n; j+=i) {
			lowestDiv[j] = (lowestDiv[j]) ? lowestDiv[j] : i;
		}
	}
	for(int i = root; i <= n; i++) {
		if(!lowestDiv[i]) {
			lowestDiv[i] = i;
		}
	}
}

// Pre-condition: preFactor must have been computed up to input n
int fastFactor(int n) {
	while(n > 1) {
		u.insert(lowestDiv[n]);
		n /= lowestDiv[n];
	}
	if(n > 1) return u.size() + 1;
	return u.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	preFactor(FACTOR_LIM-1);
	while(cin >> n, n) {
		u.clear();
		int res = fastFactor(n);
		cout << n << " : " << res << "\n";
	}
	return 0;
}
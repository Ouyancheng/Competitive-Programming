#include<iostream>
#include<vector>

using namespace std;

long long n, k, i;
long long dp[52];
vector<long long> v;

int main(void) {
	cin >> n >> k;
	dp[1] = 1;
	long long cur = 1;

	while(dp[cur] <= n) {
		cur++;
		for(i = max(0LL,cur-k); i < cur; i++) {
			dp[cur] += dp[i];
		}
	}
	
	while(cur >= 0) {
		if(dp[cur] <= n) {
			n -= dp[cur];
			v.push_back(dp[cur]);
		}
		cur--;
	}
	cout << v.size() << "\n" << v[0];
	for(int j = 1; j < v.size(); j++)
		cout << " " << v[j];
	puts("");
	return 0;
}
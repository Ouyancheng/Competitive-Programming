#include "majority.h"
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 2;
const int maxa = 1e6 + 2;

int cnt[maxa], a, pm[maxa], ans = 1;
vector< pair<int,int> > v[maxn];

int get(int x, int k) {
	int lo = 0, hi = (int) v[x].size() - 1, ans = -1;
	while(lo <= hi) {
		int mid = lo + hi >> 1;

		if(v[x][mid].first > k) {
			lo = mid + 1;
		} else {
			ans = mid;
			hi = mid - 1;
		}
	}
	return ans;
}

int majority(int N, int A[]) {
    memset(pm, -1, sizeof pm);
	for(int i = 0; i < N; i++) {
	    a = A[i];
		int sum = -i + 2 * cnt[a] + 1;
		cnt[a]++;
		int t = get(a, sum);
		if(t != -1) {
			ans = max(ans, cnt[a] - v[a][t].second + 1);
		}
		if((int) v[a].size() == 0 || sum < pm[a]) {
			v[a].push_back({sum, cnt[a]});
			pm[a] = sum;
		}
	}
	return min(ans * 2 - 1, N);
}
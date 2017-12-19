#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;
const int maxm = 3e5 + 5;
const int maxk = 3e5 + 5;

int n, m, k, a, b, c;
vector<int> ato[maxk], ic[maxm];
int ql[maxk], qr[maxk], sup[maxk], lo[maxn], hi[maxn], req[maxn];

ll fwt[maxm];

void upd(int x, int v) {
	while(x <= m) {
		fwt[x] += v;
		x += (x & -x);
	}
}

void upd(int i, int j, int v) {
	upd(i, v);
	upd(j+1, -v);
}

ll qry(int x) {
	ll ans = 0;
	while(x) {
		ans += fwt[x];
		x -= (x & -x);
	}
	return ans;
}

void rst() {
	for(int i = 1; i <= m; i++) {
		fwt[i] = 0;
	}
}

void work() {
	while(1) {
		ll sum = 0;
		bool can = 0;
		rst();
		for(int i = 1; i <= n; i++) {
			if(can |= (lo[i] < hi[i])) {
				int mid = lo[i] + hi[i] >> 1;
				ato[mid].push_back(i);
			}
		}
		for(int i = 1; i <= k; i++) {
			if(ql[i] <= qr[i]) {
				upd(ql[i], qr[i], sup[i]);
			} else {
				upd(ql[i], m, sup[i]);
				upd(1, qr[i], sup[i]);
			}
			while((int)ato[i].size()) {
				int cur = ato[i].back();
				ato[i].pop_back();

				ll sum = 0;
				for(int x : ic[cur]) {
					sum += qry(x);
					if(req[cur] <= sum) {
						break;
					}
				}
				if(req[cur] <= sum) {
					hi[cur] = i;
				} else {
					lo[cur] = i + 1;
				}
			}
		}
		if(!can) {
			break;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &a);
		ic[a].push_back(i);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		req[i] = a;
	}
	scanf("%d", &k);
	for(int i = 1; i <= n; i++) {
		lo[i] = 1;
		hi[i] = k+1;
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		ql[i] = a;
		qr[i] = b;
		sup[i] = c;
	}
	work();
	for(int i = 1; i <= n; i++) {
		if(hi[i] == k+1) {
			printf("NIE\n");
		} else {
			printf("%d\n", lo[i]);
		}
	}
	return 0;
}

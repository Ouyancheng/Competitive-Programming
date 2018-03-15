#include<bits/stdc++.h>

using namespace std;

const int maxn = 32;
int l, w, n, r, a[maxn], b[maxn], M[maxn];
double aa[4], bb[4];

bool sub(long long a, long long b) {
	while(a) {
		long long k = (a & -a);
		if((b&k) == 0) return 0;
		a -= k;
	}
	return 1;
}

int chk(long long mask) {
	int vmask = 0;
	for(int i = 0; i < n; i++) {
		if(mask&(1LL<<i)) vmask |= M[i];
	}
	return __builtin_popcount(vmask);
}

int f() {
	int ans = n+1; vector<int> choice; bool blk[n];
	memset(blk, 0, sizeof blk);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			double dx = aa[j]-a[i], dy = bb[j]-b[i], dt = sqrt(dx*dx+dy*dy);
			if(fabs(r-dt) <= 1e-8 || dt<r) {
				M[i] |= (1<<j);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		bool flag = 1;
		for(int j = 0; j < n; j++) {
			if(i!=j && !blk[j] && sub(M[i], M[j])) {
				blk[i] = 1;
				flag = 0;
				break;
			}
		}
		if(flag) choice.push_back(i);
	}
	for(int i = 0; i < (1<<(int)choice.size()); i++) {
		long long cur = 0; int cnt = 0;
		for(int j = 0; j<(int)choice.size(); j++) {
			if(i&(1<<j)) {
				cnt++;
				cur |= (1LL<<choice[j]);
			}
		}
		if(chk(cur) == 4) ans = min(ans, cnt);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> l >> w >> n >> r;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	aa[0] = -l/2.0, bb[0] = 0;
	aa[1] = l/2.0, bb[1] = 0;
	aa[2] = 0, bb[2] = -w/2.0;
	aa[3] = 0, bb[3] = w/2.0;

	int val = f();
	if(val == n+1) cout << "Impossible";
	else cout << val;
	cout << "\n";
}

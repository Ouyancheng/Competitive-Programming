#include<bits/stdc++.h>

// Slower solution for "historical". Implementation is exactly the same as in the editorial.
// Japanese editorial can be found here: https://www.ioi-jp.org/camp/2014/2014-sp-tasks/2014-sp-d1-historical-review.pdf
// Time-complexity is O(N^2/B + QlogQ + (N+Q)*sqrt(N)*logN)

using namespace std;

#define MAX_N 100005
#define MAX_Q 100005
#define MAX_BLOCK 320
#define ll long long
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fi first

unordered_map<int,int> u;
int fmap[MAX_N];
ll pre1[MAX_BLOCK][MAX_BLOCK];
vector<int> pre2[MAX_N];
int BLOCK,n,q,a,b,rk;
int freq[MAX_N],arr[MAX_N];
ll ans;

void compress() {
	for(int i = 0; i < n; i++) {
		fmap[i] = u[arr[i]];
	}
}

void calc1() {
	ll hi = 0;
	for(int i = 0; i < n; i+=BLOCK) {
		fill(freq,freq+n,0);
		hi = 0;
		for(int j = i; j < n; j++) {
			freq[fmap[j]]++;
			hi = max(hi,1LL*freq[fmap[j]]*arr[j]);
			if(j % BLOCK == BLOCK-1) {
				pre1[i/BLOCK][j/BLOCK] = hi;
			}
		}
	}
}

void calc2() {
	u.clear();
	for(int i = 0; i < n; i++) {
		pre2[fmap[i]].eb(i);
		u[fmap[i]];
	}
	for(auto p : u) {
		sort(all(pre2[p.fi]));
	}
}

int getFreq(int e,int a,int b) {
	return upper_bound(all(pre2[fmap[e]]),b) - lower_bound(all(pre2[fmap[e]]),a);
}

ll query(int a,int b) {
	ll ans = 0;
	int lbound = ((int)ceil(1.0*a/BLOCK)) * BLOCK, rbound = lbound + (b-lbound+1)/BLOCK * BLOCK - 1;
	if(rbound-lbound+1 < BLOCK) {
		for(int i = a; i <= b; i++) {
			ans = max(ans,1LL*getFreq(i,a,b)*arr[i]);
		}
	} else {
		ans = max(ans,pre1[lbound/BLOCK][rbound/BLOCK]);
		for(int i = lbound-1; i >= a; i--) {
			ans = max(ans,1LL*getFreq(i,a,b)*arr[i]);
		}
		for(int i = rbound+1; i <= b; i++) {
			ans = max(ans,1LL*getFreq(i,a,b)*arr[i]);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	BLOCK = (int) (sqrt(n));
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		u[arr[i]] = rk++;
	}
	compress();
	calc1();
	calc2();

	for(int i = 0; i < q; i++) {
		cin >> a >> b;
		a--,b--;
		cout << query(a,b) << "\n";
	}
	return 0;
}

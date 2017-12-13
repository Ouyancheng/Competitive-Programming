#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define vll vector<ll>
//#define debug

ll N,a,in[105],dis[105],t, cr[105][1];
vector<ll> cyc;

void dfs(ll cur) {
	dis[cur] = ++t;
	ll dst = cr[cur][0];
	if(!dis[dst]) {
		dfs(dst);
	} else if(dis[dst]<=dis[cur]) {
		ll len = (dis[cur]-dis[dst]+1);
		if(len&1) {
			cyc.push_back(len);
		} else {
			cyc.push_back(len/2);
		}
	}
}

int main() {
#ifdef debug
	freopen("in", "r", stdin);
#else
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#endif
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a;
		cr[i][0] = a;
		in[a]++;
	}
	for(int i = 1; i <= N; i++) {
		if(in[i] == 0) {
			cout << "-1" << "\n";
			return 0;
		}
	}
	for(int i = 1; i <= N; i++) {
		if(!dis[i]) dfs(i);
	}
	ll lcm = cyc[0];
	for(int i = 1; i < cyc.size(); i++) {
		lcm = (lcm * cyc[i]) / __gcd(lcm,cyc[i]);
	}
	cout << lcm << "\n";
	return 0;
}
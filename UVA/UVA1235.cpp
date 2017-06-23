#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<unordered_map>
#include<climits>
#include<queue>
#include<cmath>
#include<set>
#include<cstdlib>
#include<utility>

using namespace std;

#define ll long long
#define vprint(a,sz) rep(0,sz,cz) cout << setw(3) << right << a[cz] << " "; cout << endl
#define mprint(a,rn,cn) rep(0,rn,ci) { vprint(a[ci],cn); cout << endl; }
#define valid(r,c,rn,cn) (r >= 0 && c >= 0 && r < rn && c < cn)
#define ntc(a) (char) (a + 'A')
#define ctn(a) a - 65
#define make_pair mp
#define pb push_back
#define sz size()
#define p32 pair<int,int>
#define p64 pair<ll,ll>
#define pdd pair<double,double>
#define fi first
#define se second
#define tse se.fi
#define th se.se
#define tri pair<double,pdd>
#define repn(i,e) for(int i = 0; i < e; i++)
#define repsn(i,s,e) for(int i = s; i < e; i++)
#define v64 vector<ll>
#define v32 vector<int>
#define vp64 vector<p64>
#define vp32 vector<p32>
#define NL 501

int par[NL],tmp[NL],T,N;
tri el[NL*NL];

int dist(int x,int y) {
	int ans = 0;
	repn(i,4) {
		int xx = (x/int(pow(10,i)) % 10), yy = (y/int(pow(10,i)) % 10);
		if(xx > yy) xx = (xx^yy)^(yy=xx);
		ans += min((xx+10)-yy,abs(yy-xx));
	}
	return ans;
}
int find(int x) { return (par[x]==x) ? x : par[x]=find(par[x]);}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--) {
		int ei = 0, ans = 0, tc = 0, mins = 1 << 30;
		cin >> N;
		repn(i,N) par[i] = i,cin >> tmp[i];
		repn(i,N) {
			repsn(j,i+1,N) {
				el[ei].tse = i, el[ei].th = j, el[ei].fi = dist(tmp[i],tmp[j]);
				ei++;
			}
		}
		sort(el,el+ei);
		repn(i,ei) {
			if(tc == N) break;
			int u = el[i].tse, v = el[i].th, d = el[i].fi;
			if(find(u)!=find(v)) {
				par[find(u)] = find(v);
				ans += d, tc++;
			}
		}
		repn(i,N) mins = min(mins,dist(0,tmp[i]));
		cout << ans+mins << endl;
	}
	return 0;
}
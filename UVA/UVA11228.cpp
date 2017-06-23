#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

#define ll long long
#define pb push_back
#define sz size()
#define CTL 1001
#define THL 1001
#define pdd pair<double,double>
#define fi first
#define se second
#define tse se.fi
#define th se.se
#define tri pair<double,pdd>
#define repn(i,e) for(int i = 0; i < e; i++)
#define repsn(i,s,e) for(int i = s; i < e; i++)

int par[CTL];
int tr[THL];
tri el[CTL*CTL];
pdd tmp[CTL*CTL];

double dist(pdd x,pdd y) { return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)); }
int find(int x) { return (par[x]==x) ? x : par[x]=find(par[x]);}

int T,N,cn;
double R;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--) {
		int ei = 0,fa = 0,tc = 0; double sa = 0,ta = 0;
		cin >> N >> R;
		repn(i,N) par[i] = i, cin >> tmp[i].fi >> tmp[i].se;
		repn(i,N) {
			repsn(j,i+1,N) {
				el[ei].tse = i, el[ei].th = j, el[ei].fi = dist(tmp[i],tmp[j]);
				ei++;
			}
		}
		sort(el,el+ei);
		repn(i,ei) {
			if(tc == N) break;
			int u = el[i].tse, v = el[i].th;
			if(find(u)!=find(v)) {
				tc++;
				par[find(u)] = find(v);
				if(el[i].fi <= R) sa+=el[i].fi; else ta+=el[i].fi, fa++;
			}
		}
		cout << "Case #" << ++cn << ": " << ++fa << " " << int(round(sa)) <<  " " << int(round(ta));
		cout << endl;
	}
	return 0;
}

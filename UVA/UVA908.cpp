#include<iostream>
#include<cstdio>
#include<vector>
#include<iomanip>
#include<climits>
#include<queue>

using namespace std;

#define rep(a,b,c) for(int c=a;c<b;c++)
#define reps(a,b,c,s) for(int c=a;c<b;c+=s)
#define vprint(a,sz) rep(0,sz,cz) cout << setw(3) << right << a[cz] << " "; cout << endl
#define mprint(a,rn,cn) rep(0,rn,ci) { vprint(a[ci],cn); cout << endl; }
#define valid(v,r,c,rn,cn) (r >= 0 && c >= 0 && r < rn && c < cn)
#define ntc(a) (char) (a + 'A')
#define ctn(a) a - 65

typedef std::vector<int> VI;
typedef std::vector<VI> VVI;
typedef std::vector<long> VL;
typedef std::pair<long long,int> PLI;
typedef std::vector<PLI> VPI;
typedef std::vector<VPI> VVPI;

typedef priority_queue<PLI,vector<PLI>,greater<PLI> > PQ;

void path(VVPI &weight,VL &sp,PQ &next,VL &parent,VL &vis) {
	next.push(PLI(0,0));
	while(!next.empty()) {
		PLI e = next.top();
		next.pop();
		int ew = e.first,ed = e.second;
		vis[ed] = 1;
		VPI nbr = weight[ed];
		if(ew  == sp[ed]) {
			rep(0,nbr.size(),i) {
				int nw = nbr[i].first,nd = nbr[i].second;
				if(!vis[nd] && nw < sp[nd]) {
					sp[nd] = nw;
					next.push(PLI(nw,nd));
					parent[nd] = ed;
				}
			}
		}
	}
}

int main(void) {
	VVPI weight;
	VL sp,parent,vis;
	PQ next;
	int n = 0, m = 0, k = 0, a = 0, b = 0, c = 0;

	while(cin >> n) {
		int cost = 0;
		weight.assign(n,VPI());
		sp.assign(n,LLONG_MAX);
		parent.assign(n,-1);
		vis.assign(n,0);

		rep(0,n-1,i) {
			scanf("%d %d %d",&a,&b,&c);
			weight[a-1].push_back(PLI(c,b-1));
			weight[b-1].push_back(PLI(c,a-1));
			cost += c;
		}
		printf("%d\n",cost);
		cost = 0;

		scanf("%d",&k);
		rep(0,k,i) {
			scanf("%d %d %d",&a,&b,&c);
			weight[a-1].push_back(PLI(c,b-1));
			weight[b-1].push_back(PLI(c,a-1));
		}
		scanf("%d",&m);
		rep(0,m,i) {
			scanf("%d %d %d",&a,&b,&c);
		}
		sp[0] = 0;

		path(weight,sp,next,parent,vis);
		for(int i = 0; i < sp.size(); i++) {
			cost += sp[i];
		}
		printf("%d\n",cost);
		cin >> ws;
		if(!cin.eof())
			cout << endl;
	}
	return 0;
}

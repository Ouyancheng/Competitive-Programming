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
typedef std::pair<int,int> PII;
typedef std::vector<PII> VPI;

#define N 999
#define M 999

typedef pair<int,PII> PIP;
typedef priority_queue<PIP,vector<PIP>,greater<PIP> > PQ;

void adj(VVI &weight,VPI &nb,int r,int c,int n,int m) {
	if(valid(weight,r+1,c,n,m)) 
		nb.push_back(PII(r+1,c));
	if(valid(weight,r-1,c,n,m)) 
		nb.push_back(PII(r-1,c));
	if(valid(weight,r,c+1,n,m)) 
		nb.push_back(PII(r,c+1));
	if(valid(weight,r,c-1,n,m)) 
		nb.push_back(PII(r,c-1));
}

void path(VVI &weight,VVI &sp,PQ &next,int n,int m) {
	VPI nbr;
	next.push(PIP(weight[0][0],PII(0,0)));
	while(!next.empty()) {
		nbr.clear();
		PIP e = next.top();
		next.pop();
		int ew = e.first,er = e.second.first, ec = e.second.second;
		adj(weight,nbr,er,ec,n,m);
		if(ew  == sp[er][ec]) {
			rep(0,nbr.size(),i) {
				int nr = nbr[i].first,nc = nbr[i].second;
				if(weight[nr][nc] + ew < sp[nr][nc]) {
					sp[nr][nc] = weight[nr][nc] + ew;
					next.push(PIP(sp[nr][nc],PII(nr,nc)));
				}
			}
		}
	}
}

int main(void) {
	VVI weight,vis,sp;
	PQ next;
	int cc = 0,n = 0, m = 0;

	weight.assign(N,VI(M,0));
	scanf("%d",&cc);

	rep(0,cc,i) {
		sp.assign(N,VI(M,INT_MAX));
		scanf("%d %d",&n,&m);
		rep(0,n,j) {
			rep(0,m,k)
				scanf("%d",&weight[j][k]);
		}
		sp[0][0] = weight[0][0];
		path(weight,sp,next,n,m);
		printf("%d\n",sp[n-1][m-1]);
	}
	return 0;
}

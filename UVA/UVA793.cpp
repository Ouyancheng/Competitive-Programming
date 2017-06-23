#include<iostream>
#include<cstdio>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
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

int find(VI &par,int a) {
	if(par[a] == a)
		return a;
	int p = find(par,par[a]);
	return par[a] = p;
}

void join(VI &par,VI &rank,int a,int b) {
	int pa = find(par,a);
	int pb = find(par,b);
	if(pa == pb)
		return;
	if(rank[pa] < rank[pb]) {
		par[pa] = par[pb];
	} else if(rank[pa] > rank[pb]) {
		par[pb] = par[pa];
	} else {
		par[pa] = par[pb];
		rank[pb]++;
	}
}

int main(void) {
	VI par,rank;
	int cc = 0, ec  = 0, a = 0, b = 0;
	char c;

	scanf("%d",&cc);

	rep(0,cc,i) {
		int s = 0,u = 0;
		scanf("%d",&ec);
		cin >> ws;
		rank.assign(ec+1,0);
		par.clear();
		rep(0,ec+1,j) {
			par.push_back(j);
		}
		while(cin.peek() == 'q' || cin.peek() == 'c') {
			scanf("%c %d %d",&c,&a,&b);
			if(c == 'c') {
				join(par,rank,a,b);
			} else if(c == 'q') {
				int pa = find(par,a);
				int pb = find(par,b);
				if(pa == pb) {
					s++;
				} else {
					u++;
				}
			}
			cin >> ws;
		}
		printf("%d,%d\n",s,u);
		if(!cin.eof())
			printf("\n");
	}
}

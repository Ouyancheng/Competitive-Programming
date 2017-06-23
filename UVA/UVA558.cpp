#include<cstdio>
#include<vector>

using namespace std;

#define inf 999999999

vector<long long> sssp;

bool relax(int u,pair<long long,long long> v) {
	if(sssp[u] + v.second < sssp[v.first]) {
		sssp[v.first] = sssp[u] + v.second;
		return true;
	}
	return false;
}

void bf(vector<vector<pair<long long,long long> > > sys) {
	bool conv = false;
	for(int u = 0; u < sys.size()-1 && !conv; u++) {
		conv = true;
		for(int i = 0; i < sys.size(); i++) {
			for(int j = 0; j < sys[i].size(); j++) {
				pair<long long,long long> v = sys[i][j];
				conv &= !relax(i,v);
			}
		}
	}

	for(int i = 0; i < sys.size(); i++) {
		for(int j = 0; j < sys[i].size(); j++) {
			pair<long long,long long> v = sys[i][j];
			if(relax(i,v)) {
				printf("possible\n");
				return;
			}
		}
	}
	printf("not possible\n");
}

int main(void) {
	int cc,sc,wc,u,v,w;
	scanf("%d",&cc);
	while(cc--) {
		vector<vector<pair<long long,long long> > > sys;
		scanf("%d %d",&sc,&wc);
		sssp.assign(sc,inf);
		sssp[0] = 0;
		sys.assign(sc,vector<pair<long long,long long> >());
		while(wc--) {
			scanf("%d %d %d",&u,&v,&w);
			sys[u].push_back(pair<long long,long long>(v,w));
		}
		bf(sys);
	}
	return 0;
}

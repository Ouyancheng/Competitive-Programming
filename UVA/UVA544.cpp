#include<cstdio>
#include<unordered_map>
#include<queue>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

priority_queue<pair<int,int> > pq;
unordered_map<string,int> um;
vector<vector<pair<int,int> > > edges;
vector<bool> vis;

void proc(int u) {
	vis[u] = true;
	vector<pair<int,int> > adj = edges[u];
	for(int i = 0; i < adj.size(); i++) {
		int w = adj[i].second, v = adj[i].first;
		if(!vis[v]) {
			pq.push(pair<int,int>(w,v));
		}
	}
}

int main(void) {
	int a,b,w,cc = 1;
	char * p1 = (char *) (malloc(30*sizeof(char))), * p2 = (char *) (malloc(30*sizeof(char)));
	string c,d;
	while(scanf("%d %d",&a,&b) && (a|b)) {
		int n = 0;
		edges.assign(a,vector<pair<int,int > >());
		um.clear();
		vis.assign(200,false);
		pq = priority_queue<pair<int,int> >();
		while(b-- >= 1) {
			scanf("%s %s %d",p1,p2,&w);
			c = p1,d = p2;
			if(um.find(c) == um.end()) um.insert(pair<string,int>(c,n++));
			if(um.find(d) == um.end()) um.insert(pair<string,int>(d,n++));
			edges[um[c]].push_back(pair<int,int>(um[d],w));
			edges[um[d]].push_back(pair<int,int>(um[c],w));
		}
		scanf("%s %s",p1,p2);
		c = p1, d = p2;
		int ans = 99999999;
		proc(um[c]);
		while(pq.size() > 0 && !vis[um[d]]) {
			int w = pq.top().first, v = pq.top().second;
			pq.pop();
			if(!vis[v]) {
				proc(v);
				ans = min(ans,w);
			}
		}
		printf("Scenario #%d\n%d tons\n\n",cc++,ans);
	}
	free(p1);
	free(p2);

	return 0;
}

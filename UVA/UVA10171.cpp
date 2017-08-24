#include<bits/stdc++.h>

using namespace std;

#define MAX_N 1005
#define fi first
#define se second
#define mp make_pair

vector<pair<int,int>> ygraph[MAX_N];
vector<pair<int,int>> ograph[MAX_N];
priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
int yto[MAX_N], oto[MAX_N], n, m, c, c5;
map<char,int> names; map<int,char> rmap;
char c1,c2,c3,c4;
vector<char> out;

void addEdge(vector<pair<int,int>> graph[],int u,int v,int w) {
	graph[u].emplace_back(v,w);
}

void dijkstra(int u,vector<pair<int,int>> graph[],int to[]) {
	fill(to,to+n,INT_MAX);
	while(pq.size() > 0) pq.pop();
	pq.emplace(0,u);
	to[u] = 0;
	int t = 0;
	while(pq.size() > 0 && t < n) {
		pair<int,int> e = pq.top();
		int w = e.fi, v = e.se;
		pq.pop();
		if(to[v] == w) {
			t++;
			for(auto vv : graph[v]) {
				if(to[vv.fi] > vv.se + to[v]) {
					to[vv.fi] = vv.se + to[v];
					pq.emplace(to[vv.fi],vv.fi);
				}
			}
		}
	}
}

void addName(char cc) {
	if(names.find(cc) == names.end()) {
		names[cc] = c;
		rmap[c] = cc;
		c++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 0;
	while(cin >> m) {
		if(!m) break;
		int ans = INT_MAX;
		c = 0;
		names.clear();
		rmap.clear();
		out.clear();
		for(int i = 0; i < m; i++) {
			cin >> c1 >> c2 >> c3 >> c4 >> c5;
			addName(c3); addName(c4);
			if(c1 == 'Y') {
				addEdge(ygraph,names[c3],names[c4],c5);
				if(c2 == 'B')
					addEdge(ygraph,names[c4],names[c3],c5);
			} else {
				addEdge(ograph,names[c3],names[c4],c5);
				if(c2 == 'B')
					addEdge(ograph,names[c4],names[c3],c5);
			}
		}
		cin >> c1 >> c2;
		addName(c1); addName(c2);
		n = (int) names.size();

		dijkstra(names[c1],ygraph,yto);
		dijkstra(names[c2],ograph,oto);

		for(int i = 0; i < n; i++) {
			if(oto[i] != INT_MAX && yto[i] != INT_MAX) {
				ans = min(ans,oto[i] + yto[i]);
			}
		}
		if(ans == INT_MAX) {
			cout << "You will never meet.";
		} else {
			for(int i = 0; i < n; i++) {
				if(oto[i] == INT_MAX || yto[i] == INT_MAX)
					continue;
				if(oto[i] + yto[i] != ans)
					continue;
				out.emplace_back(rmap[i]);
			}
			sort(out.begin(), out.end());
			cout << ans << " ";
			for(int i = 0; i < (int) out.size(); i++) {
				cout << out[i];
				if(i < (int) out.size()-1) cout << " ";
			}
		}
		cout << "\n";
		for(int i = 0; i < n; i++) ygraph[i].clear();
			for(int i = 0; i < n; i++) ograph[i].clear();
		}
	return 0;
}

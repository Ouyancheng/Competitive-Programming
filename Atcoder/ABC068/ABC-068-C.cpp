#include<iostream>
#include<vector>
#include<queue>
#include<utility>
 
using namespace std;
 
int n,m,a,b;
vector<int> g[200005];
queue<pair<int,int>> q;
bool vis[200005];
 
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vis[1] = 1;
	q.push(make_pair(1,0));
	while((int)q.size()) {
		auto f = q.front();
		q.pop();
		for(auto p : g[f.first]) {
			if(!vis[p]) {
				vis[p] = 1;
				q.push(make_pair(p,f.second+1));
				if(f.second+1 > 2) {
					cout << "IMPOSSIBLE" << "\n";
					return 0;
				} else if (p == n) {
					cout << "POSSIBLE" << "\n";
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}
#include<bits/stdc++.h>
 
using namespace std;
 
#define REPN(i,e) for(int i = 0; i < e; i++)
#define MAX_V 50001
 
int matchU[MAX_V], matchV[MAX_V], dist[MAX_V];
vector<int> graph[MAX_V];
queue<int> q;
// Helper function for hcmatch
// Uses bfs to check for shortest augmenting paths
bool hasAugmentingPath(int n) {
	REPN(u,n) {
		if(matchU[u] == MAX_V-1) {
			dist[u] = 0;
			q.push(u);
		} else {
			dist[u] = INT_MAX;
		}
	}
 
	dist[MAX_V-1] = INT_MAX;
 
	while(q.size()) {
		int u = q.front();
		q.pop();
 
		vector<int> adj = graph[u];
 
		if(dist[u] < dist[MAX_V-1]) {
			REPN(i,adj.size()) {
				int nextU = matchV[adj[i]];
				if(dist[nextU] == INT_MAX) {
					dist[nextU] = dist[u] + 1;
					q.emplace(nextU);
				}
			}
		}
	}
	return dist[MAX_V-1] != INT_MAX;
}
 
// helper function for hcmatch
// uses dfs to trace and record vertex-disjoint
// augmenting paths
bool findpath(int u) {
	if(u != MAX_V-1) {
		vector<int> adj = graph[u];
		REPN(i,adj.size()) {
			int nextU = matchV[adj[i]];
			if(dist[nextU] == dist[u] + 1) {
				if(findpath(nextU)) {
					matchU[u] = adj[i];
					matchV[adj[i]] = u;
					return true;
				}
			}
		}
		dist[u] = INT_MAX;
		return false;
	}
	return true;
}
 
// Pre-condition:
// The global variable nil must exist
// The following data structures must exist and have size |V|+1
// int matchU[] --> Indexing must be zero-based
// int matchV[] --> Indexing must be zero-based
// int dist[] --> Indexing must be zero-based
// vector<int> graph[] -> must also be bipartite
// and unweighted
// Parameters:
// int n: number of vertices in the first partition
// int m: number of vertices in the second partition
// Post-condition: Runs the hopcroft-karp max-bipartite
// matching algorithm to find maximum matching on graph[]
// Returns the number of matched vertex pairs
// Saves the matching information in arrays
// matchU[] and matchV
// Time-complexity: O(|E|sqrt(|V|))
int hcmatch(int n,int m) {
	int ans = 0;
	fill(matchU,matchU+n,MAX_V-1);
	fill(matchV,matchV+m,MAX_V-1);
	fill(dist,dist+n,0);
	while(hasAugmentingPath(n)) {
		REPN(u,n) {
			if(matchU[u] == MAX_V-1 && findpath(u)) {
				ans++;
			}
		}
	}
	return ans;
}
 
int n,m,a,x,y;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a;
    REPN(i,a) {
        cin >> x >> y;
        x--,y--;
        graph[x].emplace_back(y);
    }
    cout << hcmatch(n,m) << "\n";
    return 0;
} 
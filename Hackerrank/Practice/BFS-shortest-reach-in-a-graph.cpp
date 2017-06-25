#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
    public:
        vector<vector<int>> Alist;
        
        Graph(int n) {
            Alist.assign(n,vector<int>());
        }
    
        void add_edge(int u, int v) {
            Alist[u].push_back(v);
            Alist[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            queue<int> nx;
            vector<bool> vis(Alist.size());
            vector<int> d;
            d.assign(Alist.size(),-1);
            d[start] = 0;
            int v = 0;
            nx.push(start);
            while(nx.size() && v < Alist.size()) {
                int e = nx.front();
                nx.pop();
                if(!vis[e]) {
                    v++;
                    vis[e] = true;
                    vector<int> adj = Alist[e];
                    for(int i = 0; i < adj.size(); i++) {
                        if(!vis[adj[i]]) {
                            nx.push(adj[i]);
                            if(d[adj[i]] == -1 || d[e] + 6 < d[adj[i]])
                              d[adj[i]] = d[e] + 6;
                        }
                    }
                }
            }
            return d;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

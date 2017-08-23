#include<bits/stdc++.h>

using namespace std;

#define MAX_N 100000

// variables for SCC algorithm
int n,m,a,b,c,sccComp[MAX_N];
stack<int> auxs;
vector<pair<int,int>> sccGraph[MAX_N], rsccGraph[MAX_N];
bool vis[MAX_N];

void revGraph(int u,vector<pair<int,int>> sccGraph[]) {
	vis[u] = 1;
	for(auto p : sccGraph[u]) {
		int v = p.first, w = p.second;
		rsccGraph[v].emplace_back(u,w);
		if(!vis[v]) revGraph(v,sccGraph);
	}
	auxs.emplace(u);
}

void decomposeSCC(int u,int par) {
	vis[u] = 1;
	sccComp[u] = par;
	for(auto p : rsccGraph[u]) {
		int v = p.first;
		if(!vis[v]) decomposeSCC(v,par);
	}
}

void addSCCEdge(int u,int v,int w = 0) {
	sccGraph[u].emplace_back(v,w);
}

// function to compute Strongly Connected Components
// assumes that all SCC data structures has been reset
void computeSCC() {
	for(int i = 0; i < n; i++) {
		if(!vis[i]) revGraph(i,sccGraph);
	}
	fill(vis,vis+n,0);
	while(auxs.size() > 0) {
		if(!vis[auxs.top()])
			decomposeSCC(auxs.top(),auxs.top());
		auxs.pop();
	}
}

// call this function if applying SCC algorithm on multiple tests
void resetSCC() {
	fill(sccComp,sccComp+n,0);
	fill(vis,vis+n,0);
	for(int i = 0; i < n; i++) {
		sccGraph[i].clear();
		rsccGraph[i].clear();
	}
}

void dfsPrint(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	cout << u << " ";
	for(auto p : rsccGraph[u]) {
		dfsPrint(p.first);
	}
}

void printSCC() {
	fill(vis,vis+n,0);
	for(int i = 0; i < n; i++) {
		if(i == sccComp[i]) {
			cout << i << ": ";
			dfsPrint(i);
			cout << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m) {
		if(!n && !m) {
			break;
		}
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			a--, b--;
			addSCCEdge(a,b);
			if(c == 2) addSCCEdge(b,a);
		}
		computeSCC();

		for(int i = 1; i < n; i++) {
			if(sccComp[i] != sccComp[i-1]) {
				cout << 0 << "\n";
				goto cont;
			}
		}
		cout << 1 << "\n";
		cont:
		resetSCC();
	}
	return 0;
}
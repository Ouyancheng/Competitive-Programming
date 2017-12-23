#include<bits/stdc++.h>

using namespace std;

#define MAX_N 1100

// variables for SCC algorithm
int scc_n, sccComp[MAX_N]; // *remember to intialize scc_n
stack<int> auxs;
vector<pair<int,int>> sccGraph[MAX_N], rsccGraph[MAX_N];
bool vis[MAX_N];

// user-defined variables
int m,a,b,c;

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
// assumes that all SCC data structures have been reset
void computeSCC() {
	for(int i = 0; i < scc_n; i++) {
		if(!vis[i]) revGraph(i,sccGraph);
	}
	fill(vis,vis+scc_n,0);
	while(auxs.size() > 0) {
		if(!vis[auxs.top()])
			decomposeSCC(auxs.top(),auxs.top());
		auxs.pop();
	}
}

// call this function if applying SCC algorithm on multiple tests
void resetSCC() {
	fill(sccComp,sccComp+scc_n,0);
	fill(vis,vis+scc_n,0);
	for(int i = 0; i < scc_n; i++) {
		sccGraph[i].clear();
		rsccGraph[i].clear();
	}
}

void printSCC() {
	vector<int> scc[scc_n];
	fill(scc,scc+scc_n,vector<int>());
	for(int i = 0; i < scc_n; i++) {
		scc[sccComp[i]].emplace_back(i);
	}
	for(int i = 0, t = 0; i < scc_n; i++) {
		if((int) scc[i].size() > 0) {
			cout << "Component " << t << ": ";
			for(int j = 0; j < scc[i].size(); j++) {
				cout << scc[i][j] << " ";
			}
			cout << "\n";
			t++;
		}
	}
}

int countSCC() {
	int ans = 0;
	vector<int> scc[scc_n];
	fill(scc,scc+scc_n,vector<int>());
	for(int i = 0; i < scc_n; i++) {
		scc[sccComp[i]].emplace_back(i);
	}
	for(int i = 0, t = 0; i < scc_n; i++) {
		if((int) scc[i].size() > 0) {
			ans++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2, s3, s4;
	unordered_map<string,int> um;
	um.reserve(1 << 10);
	int id = 0;

	while(cin >> scc_n >> m) {
		if(!scc_n && !m) {
			break;
		}
		resetSCC();
		id = 0;
		um.clear();
		for(int i = 0; i < scc_n; i++) {
			cin >> s1 >> s2;
			um[s1+s2] = id++;
		}
		for(int i = 0; i < m; i++) {
			cin >> s1 >> s2 >> s3 >> s4;
			addSCCEdge(um[s1+s2],um[s3+s4]);
		}
		computeSCC();
		cout << countSCC() << "\n";
	}
	return 0;
}
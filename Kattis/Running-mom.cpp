#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;

string s, u, v;
int n, r;
map<string, int> M;
vector<int> G[maxn];

bool dfs(int u, bitset<maxn> &vmask, bitset<maxn> &smask) {
	vmask[u] = 1;
	for(auto v : G[u]) {
		if(vmask[v] && smask[v]) {
			return 1;
		}
		smask[v] = 1;
		if(dfs(v, vmask, smask)) {
			return 1;
		}
		smask[v] = 0;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	n = stoi(s);
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		stringstream ss(s);
		ss >> u >> v;
		if(M.find(u) == M.end()) {
			M[u] = r++;
		}
		if(M.find(v) == M.end()) {
			M[v] = r++;
		}
		G[M[u]].push_back(M[v]);
	}
	while(getline(cin, s)) {
		bitset<maxn> x, y;	
		cout << s << " " << (dfs(M[s], x, y) ? "safe" : "trapped") << "\n";
	}
}
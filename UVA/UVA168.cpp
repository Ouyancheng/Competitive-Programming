#include<bits/stdc++.h>

using namespace std;

string s, d1, d2, d3, d4;

vector<int> G[26];
bool has[26];
int src, dst, k;

void dfs(int u, int p, int st = -1) {
	if(st == k-1) {
		cout << ((char) (p + 'A')) << " ";
		has[p] = 1;
	}
	bool can = 0;
	for(int v : G[u]) {
		if(v != p && !has[v]) {
			can = 1;
			dfs(v, u, (st + 1) % k);
			break;
		}
	}
	if(!can) {
		cout << "/" << ((char) (u + 'A')) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(getline(cin,s)) {
		if(s.back() == '\r') {
			s.pop_back();
		}
		if(s == "#") {
			break;
		}
		fill(G, G+26, vector<int>());
		memset(has, 0, sizeof has);
		stringstream f(s);
		getline(f, d1, '.');
		stringstream scs(d1);
		while(getline(scs, d2, ';')) {
			stringstream cs(d2);
			getline(cs, d3, ':');
			getline(cs, d4, ':');
			for(int i = 0; i < (int) d4.length(); i++) {
				G[d3[0]-'A'].push_back(d4[i]-'A');
			}
		}
		getline(f, d1, ' ');
		getline(f, d1, ' ');
		getline(f, d2, ' ');
		getline(f, d3);
		src = d1[0] - 'A', dst = d2[0] - 'A'; k = stoi(d3);
		dfs(src, dst);
	}
	return 0;
}

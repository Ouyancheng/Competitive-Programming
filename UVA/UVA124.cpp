#include<bits/stdc++.h>

using namespace std;

const int n = 26;

string s, s1, s2;
vector<int> G[n];
char c[n*100];
int indeg[n], len, t;
int dat[n];
bool path[n];

void dfs(char c[], int cur = 0) {
	if(cur == len) {
		c[cur] = '\0';
		cout << string(c) << "\n";
		return;
	}
	for(int i = 'a'; i <= 'z'; i++) {
		int u = i-'a';
		if(indeg[u] || !dat[u] || path[u]) {
			continue;
		}
		for(int v : G[u]) {
			indeg[v]--;
		}
		path[u] = 1;
		c[cur] = (char) i;
		dfs(c, cur + 1);
		path[u] = 0;
		for(int v : G[u]) {
			indeg[v]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(getline(cin, s)) {
		for(int i = 0; i < n; i++) {
			G[i].clear();
			dat[i] = path[i] = indeg[i] = 0;
			t = len = 0;
		}
		stringstream ss(s);
		while(getline(ss, s1, ' ')) {
			dat[(s1[0] - 'a')]++;
			len++;
		}
		getline(cin, s);
		ss.clear();
		ss.str(s);
		while(getline(ss, s1, ' ')) {
			c[t++] = s1[0];
		}
		for(int i = 0; i < t; i+=2) {
			int i1 = c[i] - 'a', i2 = c[i+1] - 'a';
			G[i1].push_back(i2);
			indeg[i2]++;
		}
		dfs(c);
		cin >> ws;
		if(!cin.eof()) {
			cout << "\n";
		}
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool vis[6][6];
bool has[6][6];
char c[10];

void mark(int u, int v) {
	vis[v][u] = vis[u][v] ^= 1;
}
void dfs(int e, int u = 0, int i = 0) {
	if(e == 0) {
		cout << string(c) << "\n";
		return;
	}
	for(int v = 1; v <= 5; v++) {
		if(v == u || !has[u][v]) {
			continue;
		}
		if(!vis[u][v]) {
			c[i] = v + '0';
			mark(u, v);
			dfs(e-1, v, i+1);
			mark(u, v);
		}
	}
}

void addEdge(int u, int v) {
	has[v][u] = has[u][v] = 1;
}

int main() {
	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 5);
	addEdge(3, 4);
	addEdge(3, 5);
	addEdge(4, 5);
	dfs(9);
	return 0;
}

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int n, a, b;
bool arr[maxn];
vector<int> graph[maxn];
vector<int> nodes;
int maxsum[maxn], minsum[maxn], par[maxn];

void addEdge(int a, int b) {
	graph[a].push_back(b);
	graph[b].push_back(a);
}

void dfs(int u, int p = 0) {
	maxsum[u] = arr[u] ? 1 : -1;
	minsum[u] = arr[u] ? 1 : -1;
	par[u] = p;
	for(auto v : graph[u]) {
		if(v != p) {
			dfs(v,u);
			if(maxsum[v] > 0) {
				maxsum[u] += maxsum[v];
			} 
			if(minsum[v] < 0) {
				minsum[u] += minsum[v];
			}
		}
	}
}

void dfsPrint(int u, int less, int p)  {
	nodes.push_back(u);
	for(auto v : graph[u]) {
		if(v != p) {
			if(less && minsum[v] < 0) {
				dfsPrint(v,less,u);
			} else if(!less && maxsum[v] > 0) {
				dfsPrint(v,less,u);
			}
		}
	}
}

void printRes() {
	dfs(1);
	int ans = -maxn;
	int rt = 0, less = 1;
	for(int i = 1; i <= n; i++) {
		int val1 = abs(maxsum[i]);
		int val2 = abs(minsum[i]);
		if(val1 > ans && val1 > val2) {
			less = 0;
			rt = i;
		} else if(val2 > ans && val2 > val1) {
			less = 1;
			rt = i;
		}
		ans = max(ans,max(val1,val2));
	}
	cout << ans << "\n";
	dfsPrint(rt, less, par[rt]);
	cout << nodes.size() << "\n";
	if((int)nodes.size() > 0) {
		cout << nodes[0];
	}

	for(int i = 1; i < (int) nodes.size(); i++) {
		cout << " " << nodes[i];
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for(int i = 1; i <= n-1; i++) {
		cin >> a >> b;
		addEdge(a,b);
	}
	printRes();
}

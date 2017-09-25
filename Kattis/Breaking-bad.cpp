#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int MAX_N = 100005;

bool vis[MAX_N], flag = true;
int c[MAX_N],n,m;
unordered_map<string,int> trans;
vector<int> graph[MAX_N];
queue<int> q;
string s1,s2,s[MAX_N];

bool color(int u) {
	vis[u] = 1;
	q.push(u);
	c[u] = 1;

	while((int)q.size()) {
		int u = q.front();
		q.pop();
		for(auto v : graph[u]) {
			if(c[v] == c[u]) {
				return false;
			}
			if(!vis[v]) {
				c[v] = !c[u];
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		c[i] = -1;
		trans[s[i]] = i;
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> s1 >> s2;
		graph[trans[s1]].push_back(trans[s2]);
		graph[trans[s2]].push_back(trans[s1]);
	}
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		if(!color(i)) {
			flag = false;
			break;
		}
	}
	if(!flag) {
		cout << "impossible";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		if(c[i]) continue;
		cout << s[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < n; i++) {
		if(!c[i]) continue;
		cout << s[i] << " ";
	}
	cout << "\n";
	return 0;
}
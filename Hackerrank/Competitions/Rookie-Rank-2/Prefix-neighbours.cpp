#include<bits/stdc++.h>

using namespace std;

#define TRIE_ALPHA 26
#define to_index(x) (x)-'A'
#define to_value(x) ((char) ((x)+'A'))
#define MAX_N 400005
#define ll long long

int n,val[MAX_N];
string s;
vector<int> graph[MAX_N];
unordered_map<string,int> M;
ll dp[MAX_N][2], ans;
bool vis[MAX_N];

void addEdge(int a,int b) {
	graph[b].emplace_back(a);
	graph[a].emplace_back(b);
}

struct TrieNode {
	TrieNode * child[TRIE_ALPHA];
	bool leaf;
	int idx,cnt;

	TrieNode(bool o=0) {
		memset(child,0,sizeof child);
		leaf = o;
		cnt = 1;
	}
};

struct Trie {
	TrieNode * root;
	int trie_sz;

	Trie() {
		root = new TrieNode();
	}

	void clear() {
		memset(root->child,0,sizeof root->child);
		trie_sz = 0;
	}

	void insert(const string &s) {
		int len = (int) s.length();
		if(len == 0) return;
		trie_sz++;
		TrieNode * cur = root;
		for(int i = 0; i < len; i++) {
			if(cur->child[to_index(s[i])]==0)
				cur = (cur->child[to_index(s[i])] = new TrieNode());
			else {
				cur = (cur->child[to_index(s[i])]);
				cur->cnt++;
			}
		}
		cur->idx = M[s];
		cur->leaf = 1;
	}

	// user-defined pre-process methods
	void dfs(TrieNode * cur,int par=-1) {
		if(par>=0 && cur->leaf)
			addEdge(cur->idx,par);
		for(int i = 0; i < 26; i++) {
			if(cur->child[i]) {
				if(cur->leaf) {
					dfs(cur->child[i],cur->idx);
				} else {
					dfs(cur->child[i],par);					
				}
			}
		}
	}

	void pre() {
		for(int i = 0; i < 26; i++) {
			if(root->child[i])
				dfs(root->child[i]);
		}
	}
};

ll calc(int cur,int par,int t) {	
	if(cur >= n) return 0;
	vis[cur] = 1;
	if(dp[cur][t]) return dp[cur][t];
	for(auto p : graph[cur]) {
		if(t && p != par) {
			dp[cur][t] += calc(p,cur,0);
		} else if(!t && p != par) {
			dp[cur][t] += max(calc(p,cur,0),calc(p,cur,1));
		}
	}
	if(t) return dp[cur][t] = dp[cur][t] + val[cur];
	else return dp[cur][t];
}

int ascii(const string &s) {
	int val = 0;
	for(int i = 0; i < (int) s.length(); i++) {
		val += s[i];
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Trie t;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		M[s] = i;
		val[i] = ascii(s);
		t.insert(s);
	}
	t.pre();
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			ans = ans+max(calc(i,-1,0),calc(i,-1,1));
		}
	}
	cout << ans;

	return 0;
}
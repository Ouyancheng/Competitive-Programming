#include<bits/stdc++.h>

using namespace std;

#define TRIE_ALPHA 26
#define to_index(x) (x)-'a'
#define to_value(x) ((char) ((x)+'a'))

struct TrieNode {
	TrieNode * child[TRIE_ALPHA];
	bool leaf;

	TrieNode(bool o=0) {
		memset(child,0,sizeof child);
		leaf = o;
	}
};

struct Trie {
	TrieNode * root;
	int trie_sz;

	Trie() {
		root = new TrieNode();
	}

	void clear() {
		root = new TrieNode();
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
			else
				cur = (cur->child[to_index(s[i])]);
		}
		cur->leaf = 1;
	}

	string find(const string &s) {
		int len = (int) s.length();
		if(len == 0) return 0;
		TrieNode * cur = root;
		for(int i = 0; i < len; i++) {
			if(cur->child[to_index(s[i])]) {
				cur = (cur->child[to_index(s[i])]);				
			} else {
				return "";
			}
		}
		return (cur->leaf) ? s : "";
	}

	void dfsprint(TrieNode * cur,string s="") {
		if(cur->leaf) cout << s << endl;
		for(int i = 0; i < TRIE_ALPHA; i++) {
			if(cur->child[i]) {
				dfsprint(cur->child[i],s+to_value(i));
			}
		}
	}

	void print() {
		dfsprint(root);
	}

	int size() {
		return trie_sz;
	}
};

int tt,n,a;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	Trie t;
	cin >> tt;
	while(tt--) {
	    t.clear();
	   cin >> n; 
	   for(int i = 0; i < n; i++) {
	     cin >> s;
	     t.insert(s);
	   }
	   cin >> s;
	   if(t.find(s).length()) {
	       cout << 1 << "\n";
	   } else {
	       cout << "0" << "\n";
	   }
	}
	return 0;
}
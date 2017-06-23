#include <bits/stdc++.h>
using namespace std;

string s,old;
unordered_map<char,vector<char>> um;
vector<vector<int>> adj;
bool vis[26];
list<char> rev;

int dfs(char c) {
  vis[c-'A'] = true;
  vector<char> nb = um[c];
  for(int i = 0; i < nb.size(); i++) {
      if(!vis[nb[i]-'A']) dfs(nb[i]);
  }
  rev.push_front(c);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
	while(cin >> ws && !cin.eof()) {
    	old = "";
        memset(vis,false,sizeof(vis));
        rev.clear();
        um.clear();
        adj.clear();
        rev.clear();
	    while(cin >> s && s != "#") {
    	    for(int i = 0, j = 0; i < s.length() && j < old.length(); i++, j++) {
    	        if(s[i] != old[j]) {
    	            if(um.find(old[i])==um.end()) um.insert(pair<char,vector<char>>(old[i],vector<char>()));
    	            if(um.find(s[i])==um.end()) um.insert(pair<char,vector<char>>(s[i],vector<char>()));
    	            um[old[i]].push_back(s[j]);
    	            break;
    	        }
    	    }
    	    old = s;
	    }   	    
	    for(auto p : um) if(!vis[p.first-'A']) dfs(p.first);
	    for(auto i : rev) cout << i;
	    cout << endl;
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n;
string s, s2, sn;
unordered_map<string,int> M, C;
set< pair<int,string> > R;
map< string,vector<string> > words;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	getline(cin, s2);
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		stringstream ss(s);
		getline(ss, sn, ' ');
		while(getline(ss, s2, ' ')) {
			words[sn].push_back(s2);
		}
	}
	for(auto p : words) {
		unordered_set<string> U;
		for(string w : p.second) {
			C[w]++;
			U.insert(w);
		}
		for(string tmp : U) {
			M[tmp]++;
		}
	}
	for(pair<string,int> p : M) {
		if(p.second == (int) words.size()) {
			R.insert(make_pair(-C[p.first], p.first));
		}
	}
	for(pair<int,string> p : R) {
		cout << p.second << "\n";
	}
	if((int) R.size() == 0) {
		cout << "ALL CLEAR" << "\n";
	}
	return 0;
}

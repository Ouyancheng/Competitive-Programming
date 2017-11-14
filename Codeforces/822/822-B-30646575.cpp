#include<bits/stdc++.h>

using namespace std;

string s,t;
int n1,n2,ans = -1;
vector<int> pos;

int main() {
	//freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n1 >> n2;
	cin >> s >> t;
	for(int i = 0; i < n2-n1+1; i++) {
		int match = 0;
		vector<int> tmp;
		for(int j = 0; j < n1; j++) {
			if(s[j] == t[i+j]) {
				match++;
			} else {
				tmp.push_back(j+1);
			}
		}
		if(match > ans) {
			ans = match;
			pos.clear();
			for(auto p : tmp) {
				pos.push_back(p);
			}
		}
	}
	cout << n1-ans << "\n";
	for(auto p : pos) {
		cout << p << " ";
	}
	cout << "\n";
	return 0;
}
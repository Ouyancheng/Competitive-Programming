#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(getline(cin, s)) {
		stringstream ss(s);
		string s2;
		
		vector<int> v;
		int n = -1;
		
		while(ss >> s2) {
			int a = stoi(s2);
			n = max(n, a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		map<int, int> M;
		
		for(int i = 0; i < (int) v.size(); i++) {
			for(int j = i+1; j < (int) v.size(); j++) {
				M[v[j]-v[i]]++;
				if(M[v[j]-v[i]] == 2) {
					cout << "not a ruler";
					goto end;
				}
			}
		}
		
		if((int) M.size() == n) {
			cout << "perfect";
		} else {
			cout << "missing ";
			for(int i = 1; i <= n; i++) {
				if(M.find(i) == M.end()) cout << i << " \n"[i == n];
			}
		}
		end: cout << "\n";

	}
	return 0;
}
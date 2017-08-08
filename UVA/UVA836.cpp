#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

int t, m[26][26];
string s;

int maxhistogram(int n,int rect[]) {
	vector< pair<int,int> > v;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int a = rect[i];
		if(!v.size() || v.back().fi < a) {
			v.pb(mp(a,i));
		} else {
			int lo = i, len = 0;
			while(v.size() > 0 && v.back().fi >= a) {
				ans = max(ans,(v.back().fi) * (i - v.back().se));
				lo = v.back().se;
				v.pop_back();
			}
			v.pb(mp(a,lo));
		}
	}
	while(v.size()) {
		ans = max(ans,v.back().fi * (n - v.back().se));
		v.pop_back();
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	t = stoi(s);
	getline(cin,s);
	for(int i = 0, r = 0, c = 0, ans = 0; i < t; i++, ans = r = 0) {
		while(true) {
			if(!getline(cin,s)) break;
			if(s.length() > 0 && s[s.length()-1] == '\r')
				s = s.substr(0,s.length()-1);
			if(s.length() == 0) break;
			c = 0;
			for(int j = 0; j < (int) s.length(); j++)
				m[r][c++] = (int) (s[j]-'0');
			r++;
		}
		for(int j = 0; j < r-1; j++) {
			for(int k = 0; k < c; k++) {
				if(m[j+1][k] == 1) {
					m[j+1][k] += m[j][k];
				}
			}
		}
		for(int j = 0; j < r; j++)
			ans = max(ans,maxhistogram(c,m[j]));
		cout << ans << "\n";
		if(i < t-1) cout << "\n";
	}
	return 0;
}
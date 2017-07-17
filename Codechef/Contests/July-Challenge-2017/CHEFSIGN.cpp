#include<bits/stdc++.h>
 
using namespace std;
 
string s;
int gt2[100005], gt1[100005];
int ls,gs,ans,cur;
int t;
int out[100005];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		ls = gs = ans = 0;
		cin >> s;
		int n = (int) s.length();
		for(int i = n-1; i >= 0; i--) {
			gs += (s[i] == '>');
			if(s[i] == '<') gs = 0;
			gt1[i] = gs;
		}

		for(int i = 0; i <= n-1; i++) {
			ls += (s[i] == '<');
			if(s[i] == '>') ls = 0;
			gt2[i+1] = ls;
		}

		for(int i = 0; i <= n; i++) {
			out[i] = 1+max(gt1[i],gt2[i]);
			ans = max(ans,out[i]);
		}
		cout << ans << "\n";
		/*
		for(int i = 0; i <= n; i++) {
			if(i) {
				cout << s[i-1] << " ";
			}
			cout << out[i] << " ";
		}
		cout << "\n";
		cout << endl;
		*/
	}
	return 0;
} 
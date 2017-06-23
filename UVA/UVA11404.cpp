#include<iostream>
#include<cstdio>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<climits>

using namespace std;

#define rep(a,b,c) for(int c=a;c<b;c++)
#define reps(a,b,c,s) for(int c=a;c<b;c+=s)
#define vprint(a) rep(0,a.size(),cz) cout << setw(3) << right << a[cz] << " "; cout << endl
#define mprint(a) rep(0,a.size(),ci) vprint(a[ci]);
#define valid(v,r,c) (r >= 0 && c >= 0 && r < v.size() && c < v[r].size())
#define ntc(a) (char) (a + 'A')
#define ctn(a) a - 65

typedef long long LL;
typedef std::vector<LL> VLL;
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;
typedef std::pair<int,int> PII;

string longer(string a,string b) {
	return (a.length() > b.length()) ? a : b;
}

void f(vector<vector<string> > &v,string &s,string &r) {
	for(int i = 0; i < s.length(); i++) {
		for(int j = 0; j < r.length(); j++) {
			if(s[i] == r[j]) {
				v[i+1][j+1] = v[i][j] + s[i];
			} else {
				if(v[i+1][j].length() == v[i][j+1].length())
					v[i+1][j+1] = (v[i+1][j].compare(v[i][j+1]) < 1) ? v[i+1][j] : v[i][j+1];
				else
					v[i+1][j+1] = longer(v[i+1][j],v[i][j+1]);
			}
		}
	}
}

string longestPalindrome(string s) {
	vector<vector<string> > v;
	string r = s;
	reverse(r.begin(),r.end());
	v.assign(s.length()+1,vector<string>());
	for(int i = 0; i < v.size(); i++) {
		v[i].assign(v.size(),"");
	}
	f(v,s,r);
	for(int i = 0; i < v.size(); i++) {
		cout << setw(6);
		for(int j = 0; j < v[i].size(); j++) {
			cout << setw(5) << v[i][j] << " | ";
		}
		cout << endl;
	}
	return v[v.size()-1][v.size()-1];
}

int main(void) {
	string s;
	while(cin >> s)
		cout << longestPalindrome(s) << endl;
	return 0;
}

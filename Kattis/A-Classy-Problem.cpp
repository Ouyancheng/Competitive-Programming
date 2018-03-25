#include<bits/stdc++.h>

using namespace std;

const int maxn = 105;

int t, n;
map<string, string> R;
string o[maxn], a, b, s;

bool cmp(string &a, string &b) {
	string u = R[a], v = R[b];
	int n1 = u.length(), n2 = v.length();
	for(int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0; i--, j--) {
		char c1 = (i < 0) ? '1' : u[i];
		char c2 = (j < 0) ? '1' : v[j];
		if(c1 > c2) {
			return 1;
		} else if(c1 < c2) {
			return 0;
		}
	}
	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		R.clear();
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> s >> a >> b;
			s.pop_back();
			o[i] = s;
			stringstream ss(a);
			string s2;
			while(getline(ss, s2, '-')) {
				if(s2 == "upper") {
					R[s] += "2";
				} else if(s2 == "middle") {
					R[s] += "1";
				} else { // must be lower
					R[s] += "0";
				}
			}
		}
		sort(o, o + n, cmp);
		for(int i = 0; i < n; i++) {
			cout << o[i] << "\n";
		}
		cout << "==============================" << endl;
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

vector<pair<int,double>> v;
string s;
int change;
vector<string> sp;
double total;

int sec(string &st) {
	int h = stoi(st.substr(0,2));
	int m = stoi(st.substr(3,2));
	int s = stoi(st.substr(6,2));

	return h * 3600 + m * 60 + s;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	cout << fixed;
	v.push_back({0,0});
	sp.push_back("0");
	while(getline(cin, s)) {
		stringstream ss(s);
		string t;
		int i1 = 0; double i2 = -1;
		getline(ss, t, ' ');
		if(t.back() == '\r') {
			t.pop_back();
		}
		sp.push_back(t);
		i1 = sec(t);
		if(getline(ss, t, ' ')) {
			i2 = stod(t)/3600;
		}
		v.push_back({i1, i2});
	}
	for(int i = 1; i < (int) v.size(); i++) {
		total += (v[i].first - v[i-1].first) * v[change].second;
		if(v[i].second < 0) {
			cout << sp[i] << " " << total << " km\n";
		} else {
			change = i;
		}
	}
	return 0;
}
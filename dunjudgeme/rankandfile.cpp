#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

int m[50][50];
int n,a;
vector<int> v;
unordered_map<int,int> um;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < 2*n-1; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a;
			um[a]++;
		}
	}
	for(auto p : um) {
		if(p.second&1) {
			v.push_back(p.first);
		}
	}
	sort(v.begin(),v.end());
	cout << v[0];
	for(int i = 1; i < v.size(); i++) {
		cout << " " << v[i];
	}
	cout << endl;
	return 0;
}
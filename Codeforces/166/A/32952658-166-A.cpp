#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

vector< pair<int,int> > v;
int a, b, rk = 1, n, k;
int out[100];

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first > p2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(pair<int,int>(a,b));
	}
	sort(v.begin(),v.end(),cmp);

	out[1] = 1;

	for(int i = 1; i < (int) v.size(); i++) {
		if(v[i].first != v[i-1].first || v[i].second != v[i-1].second) {
			rk++;
		}
		out[rk]++;
	}
	for(int i = 1, sum = 0; i <= n; i++) {
		sum += out[i];
		if(k <= sum) {
			cout << out[i] << "\n";
			return 0;
		}
	}
	return 0;
}
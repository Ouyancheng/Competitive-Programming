#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 100005;
int x, n, q, dis, cur, to[maxn], t[maxn], out[maxn], a[maxn];
vector< pair<int,int> > v;

void work() {
	for(int i = 1; i < maxn; i++) {
		t[i] = n;
	}
	for(int i = n-1; i >= 0; i--) {
		if(t[a[i]] == n) {
			dis++;
		}
		to[i] = t[a[i]];
		t[a[i]] = i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	work();
	for(int i = 0; i < q; i++) {
		cin >> x;
		v.push_back(make_pair(--x,i));
	}
	sort(v.begin(),v.end());
	for(int i = 0; i < (int) v.size(); i++) {
		while(v[i].first > cur) {
			if(to[cur++] == n) {
				dis--;
			}
		} 
		out[v[i].second] = dis;
	}
	for(int i = 0; i < q; i++) {
		cout << out[i] << "\n";
	}
	return 0;
}

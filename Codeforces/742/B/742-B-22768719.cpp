#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N,x,a,count = 0;
	unordered_map<ll,ll> u;
	
	cin >> N >> x;
	for(int i = 0; i < N; i++) {
		cin >> a;
		count += u[a^x];
		u[a]++;
	}
	cout << count << "\n";
	
	return 0;
}
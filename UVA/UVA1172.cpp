#include<bits/stdc++.h>

using namespace std;

#define MAX_V 1001
#define ll long long

struct City {
	string name;
	string os;
	int value;

	City() {
		City("","",0);
	}

	City(string n,string o,int v) {
		name = n;
		os = o;
		value = v;
	}
};

int n,a,b,z,ans;
string x,y;
City bank1[MAX_V],bank2[MAX_V];
ll dp[MAX_V][MAX_V];
int match[MAX_V][MAX_V];

void solve() {
	ll xv,yv,zv;
	for(int i = a-1; i >= 0; i--) {
		for(int j = b-1; j >= 0; j--) {
			xv = 1LL*bank1[i].value+bank2[j].value+dp[i+1][j+1];
			yv = 1LL*dp[i+1][j];
			zv = 1LL*dp[i][j+1];
			if(bank1[i].os == bank2[j].os) {
				if(xv > yv && xv > zv) {
					match[i][j] = 1+match[i+1][j+1];
				} else if(yv > zv) {
					match[i][j] = match[i+1][j];
				} else {
					match[i][j] = match[i][j+1];
				}
				dp[i][j] = max({xv,yv,zv});
			} else {
				if(yv > zv) match[i][j] = match[i+1][j];
				else match[i][j] = match[i][j+1];
				dp[i][j] = max({yv,zv});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while(n--) {
		ans = 0;
		cin >> a;
		for(int i = 0; i < a; i++) {
			cin >> x >> y >> z;
			bank1[a-a+i] = City(x,y,z);
		}
		cin >> b;
		for(int i = 0; i < b; i++) {
			cin >> x >> y >> z;
			bank2[b-b+i] = City(x,y,z);
		}
		for(int i = 0; i <= a; i++) {
			for(int j = 0; j <= b; j++) {
				match[i][j] = dp[i][j] = 0;
			}
		}
		solve();
		int matched = MAX_V;
		for(int i = 0; i < a; i++) {
			for(int j = 0; j < b; j++) {
				if(dp[i][j] == dp[0][0]) {
					matched = min(matched,match[i][j]);
				}
			}
		}
		if(matched == MAX_V) matched = 0;
		cout << dp[0][0] << " " << matched << "\n";
	}
	return 0;
}
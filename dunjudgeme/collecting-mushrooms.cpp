#include<bits/stdc++.h>

using namespace std;

int r, c, d, k, ans;
char a;
int ul1, ul2, ur1, ur2, ll1, ll2, lr1, lr2;
vector< vector<long long> > S;
vector< pair<int, int> > M;
 
void upd() {
	S[ul1][ul2] += 1;
	S[ur1][ur2 + 1] -= 1;
	S[ll1 + 1][ll2] -= 1;
	S[lr1 + 1][lr2 + 1] += 1;
}

void sum() {
	for(int i = 0; i < r; i++) {
		for(int j = 1; j < c; j++) {
			S[i][j] += S[i][j - 1]; 
		}
	}
	for(int i = 1; i < r; i++) {
		for(int j = 0; j < c; j++) {
			S[i][j] += S[i - 1][j]; 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c >> d >> k;
	S.assign(r + 1, vector<long long>());
	for(int i = 0; i <= r; i++) {
		S[i].assign(c + 1, 0);
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> a;
			if(a == 'S') {
				ul1 = max(0, i - d);
				ul2 = max(0, j - d);
				ur1 = max(0, i - d);
				ur2 = min(c - 1, j + d);
				ll1 = min(r - 1, i + d);
				ll2 = max(0, j - d);
				lr1 = min(r - 1, i + d);
				lr2 = min(c - 1, j + d);
				upd();
			} else if(a == 'M') {
				M.push_back({i, j});
			}
		}
	}
	sum();
	for(int i = 0; i < (int) M.size(); i++) {
		if(S[M[i].first][M[i].second] >= k) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 2;
int n, a, ans, dat[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a;
        dat[a]++;
        if(dat[a+1] == 0) {
            ans++;
        } else {
            dat[a+1]--;
        }
	}
	cout << ans << "\n";
	return 0;
}

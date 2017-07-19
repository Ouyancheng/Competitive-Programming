#include<iostream>

using namespace std;

int n,a,cnt[5],ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}
	while(n) {
		if(cnt[4]) {
			cnt[4]--;
			n--;
		} else if(cnt[1] && cnt[3]) {
			cnt[1]--;
			cnt[3]--;
			n -= 2;
		} else if(cnt[2] >= 2) {
			cnt[2] -= 2;
			n -= 2;
		} else if(cnt[1] >= 2 && cnt[2] >= 1) {
			cnt[1] -= 2;
			cnt[2] -= 1;
			n -= 3;
		} else if(cnt[1] >= 4) {
			cnt[1] -= 4;
			n -= 4;
		} else if(cnt[2]) {
			if(cnt[1]) n--;
			n--;
		} else if(cnt[3]) {
			n--;
		} else {
			n -= cnt[1];
		}
		ans++;
	}
	cout << ans << "\n";
	return 0;
}
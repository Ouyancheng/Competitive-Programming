#include<bits/stdc++.h>

using namespace std;

int a,b,f,k,p,d,ans,f1,f2;

int main() {
	//freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> f >> k;

	f1 = f;
	f2 = abs(a-f);

	p = b;

	while(1) {
		if(d == 0) {
			if(p < f1) {
				cout << -1 << "\n";
				return 0;
			}
			p -= f1;
			if((k == 1 && p < f2 && b < f2) || (k > 1 && p < 2*f2 && b < 2*f2)) {
				cout << -1 << "\n";
				return 0;
			} else if((k == 1 && p < f2) || (k > 1 && p < 2*f2)) {
				p = b;
				ans++;
			}
			p -= f2;
		} else {
			if(p < f2) {
				cout << -1 << "\n";
				return 0;
			}
			p -= f2;
			if((k == 1 && p < f1 && b < f1) || (k > 1 && p < 2*f1 && b < 2*f1)) {
				cout << -1 << "\n";
				return 0;
			} else if((k == 1 && p < f1) || (k > 1 && p < 2*f1)) {
				p = b;
				ans++;
			}
			p -= f1;
		}
		d = 1-d;
		if(--k == 0) break;
	}
	cout << ans << "\n";

	return 0;
}
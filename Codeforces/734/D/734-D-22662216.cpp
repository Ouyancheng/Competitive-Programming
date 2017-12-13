#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	double dist[8];
	char piece[8];
	cin.tie(0);
	long long a,b,N,kr,kc;
	char c;
	cin>> N >> kr >> kc;
	memset(piece,0,8);
	fill_n(dist,8,LLONG_MAX);

	bool chk=false;
	while (N--) {
		cin >> c >> a >> b;
		if(a > kr && b < kc && abs(a-kr)==abs(b-kc)) {
			// lower left
			if(sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc)) < dist[0]) {
				dist[0] = sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc));
				piece[0] = c; 
			}
		} else if(a < kr && b > kc && abs(a-kr)==abs(b-kc)) {
			// upper right
			if(sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc)) < dist[1]) {
				dist[1] = sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc));
				piece[1] = c; 
			}
		} else if(a < kr && b < kc && abs(a-kr)==abs(b-kc)) {
			// upper left
			if(sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc)) < dist[2]) {
				dist[2] = sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc));
				piece[2] = c; 
			}
		} else if(a > kr && b > kc && abs(a-kr)==abs(b-kc)) {
			// lower right
			if(sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc)) < dist[3]) {
				dist[3] = sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc));
				piece[3] = c; 
			}
		} else if(a == kr && b < kc) {
			// left
			if(sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc)) < dist[4]) {
				dist[4] = sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc));
				piece[4] = c; 
			}
		} else if(a == kr && b > kc) {
			// right
			if(sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc)) < dist[5]) {
				dist[5] = sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc));
				piece[5] = c; 
			}
		} else if(b == kc && a < kr) {
			// above
			if(sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc)) < dist[6]) {
				dist[6] = sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc));
				piece[6] = c; 
			}
		} else if(b == kc && a > kr) {
			// below
			if(sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc)) < dist[7]) {
				dist[7] = sqrt((a-kr)*(a-kr) + (b-kc)*(b-kc));
				piece[7] = c; 
			}
		}
	}
	for(int i = 0; i < 8; i++) {
		if(piece[i]) {
			if(i >= 0 && i <= 3) {
				if(piece[i] == 'Q' || piece[i] == 'B') {
					chk = 1;
					break;
				}
			} else {
				if(piece[i] == 'Q' || piece[i] == 'R') {
					chk = 1;
					break;
				}
			} 	
		}
	}
	cout <<(chk?"YES":"NO")<< endl;
	return 0;
}
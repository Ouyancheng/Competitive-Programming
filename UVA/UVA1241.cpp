#include <iostream>
#include <bitset>

using namespace std;

int n,m,cc,a,ans,bt;
bitset<1024> mask;
bitset<1024> pre;

int main(void) {
	cin >> cc;
	for(int i = 0; i < cc; i++) {
		cin >> n >> m;
		ans = 0;
		mask = bitset<1024>();
		pre.reset();
		mask.set();
		for(int j = 0; j < m; j++) {
			cin >> a;
			mask[a-1] = 0;
		}
		a = 1<<n;
		while(a) {
			for(int j = 0; j < a-1; j+=2) {
				if((mask[j]==1 && mask[j+1]!=1) || (mask[j]!=1 && mask[j+1]==1)) ans++;
				pre[j>>1] = (mask[j]|mask[j+1]);
			}
			a >>= 1;
			mask = pre;
			pre.reset();
		}
		cout << ans << endl;
	}
   return 0;
}
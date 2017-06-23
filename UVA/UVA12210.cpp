#include<bits/stdc++.h>

using namespace std;

int bc, sc;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> bc >> sc && bc != 0 && sc != 0) {
		int b[bc],s[sc],vis[sc],cc;

		for(int i = 0; i < bc; i++) {
			cin >> b[i];
		}
		for(int i = 0; i < sc; i++) {
			cin >> s[i];
		}
		sort(b,b+bc,greater<int>());
		if(max((bc-sc),0))
			cout << "Case " << (++cc) << ": " << bc-sc << " " << b[bc-1] << "\n";
		else
			cout << "Case " << (++cc) << ": 0\n";
	}
	return 0;
}

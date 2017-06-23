#include <iostream>
#include <vector>
#include <sstream>

#define rep(a,b,c) for(int c=a;c < b; c++)
#define ntc(n) (char) (n + 'A')
#define ctn(n) n - 65
#define ALPN 26

using namespace std;

typedef vector<char> VC;
typedef vector<int> VI;
typedef stringstream SS;

int main()
{
	string str;
	SS sst;
	int cc = 0,cn = 1;
	VC path;
	VI plen,vis;
	char a;
	cin >> cc;

	while(cin >> str) {
		path.clear();
		sst.str("");
		sst.clear();
		sst << str;
		plen.assign(ALPN,0);
		vis.assign(ALPN,0);

		while(sst >> a) {
			if(!vis[ctn(a)]) {
				path.push_back(a);
				vis[ctn(a)] = 1;
			} else {
				while(!path.empty() && path.back() != a) {
					plen[ctn(a)]++;
					plen[ctn(path.back())]++;
					path.pop_back();
				}
			}
		}
		cout << "Case " << cn++ << endl;
		rep(0,plen.size(),i) {
			if(plen[i] != 0)
				cout << ntc(i) << " = " << plen[i] << endl;
		}
	}
	return 0;
}

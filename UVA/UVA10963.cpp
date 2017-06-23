#include<iostream>
#include<vector>

using namespace std;

#define rep(a,b,c) for(int c=a;c<b;c++)
#define vprint(a) rep(0,a.size(),cz) cout << setw(3) << right << a[cz] << " "; cout << endl

typedef std::vector<int> VI;

int main(void) {
	int cc = 0,ckc = 0,N,S,lo = 0,hi = 0;
	VI land;
	cin >> cc;

	rep(0,cc,i) {
		cin >> ckc;
		land.assign(201,0);
		lo = 202;
		hi = 0;
		rep(0,ckc,j) {
			cin >> N >> S;
			land[j] = abs(N - S);
			lo = min(lo,land[j]);
			hi = max(hi,land[j]);
		}
		cout << (ckc == 0 || lo == hi ? "yes" : "no") << endl;
		if(i != cc-1)
			cout << endl;
	}
}

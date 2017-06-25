#include<iostream>
#include<cstdio>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<unordered_map>
#include<climits>
#include<queue>
#include<cmath>

using namespace std;

#define rep(a,b,c) for(int c=a;c<b;c++)
#define reps(a,b,c,s) for(int c=a;c<b;c+=s)
#define vprint(a,sz) rep(0,sz,cz) cout << setw(3) << right << a[cz] << " "; cout << endl
#define mprint(a,rn,cn) rep(0,rn,ci) { vprint(a[ci],cn); cout << endl; }
#define valid(v,r,c,rn,cn) (r >= 0 && c >= 0 && r < rn && c < cn)
#define ntc(a) (char) (a + 'A')
#define ctn(a) a - 65

typedef long long LL;
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;
typedef std::pair<int,int> PII;
typedef std::vector<LL> VLL;
typedef std::vector<PII> VPI;

int hgsum(VVI &v,int r,int c) {
	int sum = 0;
	rep(r,r+3,i) {
		rep(c,c+3,j)
			sum += v[i][j];
	}
	return sum -= (v[r+1][c] + v[r+1][c+2]);
}

int main(void) {
	int a = 0;
	VVI v;
	VI tmp;
	while(cin >> a) {
		tmp.push_back(a);
	}
	v.assign(sqrt(tmp.size()),VI());
	rep(0,v.size(),i) {
		rep(0,v.size(),j) {
			v[i].push_back(tmp[v.size()*i+j]);
		}
	}
	int msum = INT_MIN;

	rep(0,v.size()-2,i) {
		rep(0,v.size()-2,j) {
			int tsum = hgsum(v,i,j);
			msum = max(msum,tsum);
		}
	}
	cout << msum << endl;
}

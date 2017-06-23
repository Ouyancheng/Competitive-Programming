#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

#define rep(a,b,c) for(int c=a;c<b;c++)

typedef std::vector<int> VI;
typedef std::vector<VI> VVI;

int query(VI &nt,int i) {
	int val = 1;
	while(i > 0) {
		val += nt[i];
		i -= (i & -i);
	}
	return val;
}

void insert(VI &nt,int i,int val) {
	while(i < nt.size()) {
		nt[i] += val;
		i += (i & -i);
	}
}

int main(void) {
	while(!cin.eof()) {
		int nc = 0, cc = 0, a = 0, b = 0;
		char c = '\0';
		cin >> nc >> cc;
		VI nt(nc+1,0);
		VI zt(nc+1,0);
		VI f(nc+1,0);
		rep(0,nc,i) {
			scanf("%d",&a);
			if(a < 0) {
				insert(nt,i+1,1);
			} else if(a == 0) {
				insert(zt,i+1,1);
			}
			f[i+1] = a;
		}			
		rep(0,cc,j) {
			cin >> c >> a >> b;
			if(c == 'C') {
				if(f[a] > 0 && b < 0) {
					insert(nt,a,1);
				} else if(f[a] < 0 && b >= 0) {
					insert(nt,a,1);
				}

				if(f[a] != 0 && b == 0) {
					insert(zt,a,1);
				} else if(f[a] == 0 && b != 0) {
					insert(zt,a,-1);
				}
				f[a] = b;
			} else if(c == 'P') {
				int zc = query(zt,b)-query(zt,a-1);
				int nc = query(nt,b)-query(nt,a-1);
				if(zc > 0)
					printf("%c",'0');
				else if(nc % 2 == 0)
					printf("%c",'+');
				else
					printf("%c",'-');
			}
		}
		cin >> ws;
		cout << endl;
	}
}

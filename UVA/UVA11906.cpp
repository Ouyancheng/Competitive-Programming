#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

#define rep(a,b,c) for(int c=a;c<b;c++)
#define reps(a,b,c,s) for(int c=a;c<b;c+=s)
#define vprint(a) rep(0,a.size(),cz) cout << setw(3) << right << a[cz] << " "; cout << endl
#define valid(v,r,c) (r >= 0 && c >= 0 && r < v.size() && c < v[r].size())

typedef std::vector<int> VI;
typedef std::vector<VI> VVI;

int jmp(VVI vis,int r,int c,int M,int N) {
	int sum = 0;
	int j[] = { r+N,c+M,r+N,c-M,r-N,c-M,r-N,c+M,r+M,c+N,r+M,c-N,r-M,c-N,r-M,c+N };
	reps(0,16,i,2) {
		if(valid(vis,j[i],j[i+1]) && vis[j[i]][j[i+1]] != -1) {
			sum +=  1;
			vis[j[i]][j[i+1]] = -1;
		}
	}
	return sum;
}

void mark(VVI &vis,int r,int c,int M,int N) {
	// if valid and not marked, mark square
	int j[] = { r+N,c+M,r+N,c-M,r-N,c-M,r-N,c+M,r+M,c+N,r+M,c-N,r-M,c-N,r-M,c+N };
	if(valid(vis,r,c) && vis[r][c] != -1) {
		if(!vis[r][c]) {
			// square is unmarked, mark it
			vis[r][c] = jmp(vis,r,c,M,N) + 2;
			// go to next available squares
			reps(0,16,i,2)
				mark(vis,j[i],j[i+1],M,N);
		}
	}
}

int main(void) {
	int cc = 0,a = 0,b = 0,c = 0,d = 0,M = 0,N = 0;
	VVI vis;

	cin >> cc;
	rep(0,cc,i) {
		vis.clear();
		cin >> a >> b >> M >> N;
		vis.assign(a,VI());
		rep(0,a,j) {
			vis[j].assign(b,0);
		}
		cin >> a;
		rep(0,a,j) {
			cin >> c >> d;
			vis[c][d] = -1;
		}
		mark(vis,0,0,M,N);
		int e = 0, o = 0;
		rep(0,vis.size(),j) {
			rep(0,vis[j].size(),k) {
				if(vis[j][k] > 0) {
					if(vis[j][k] % 2)
						o++;
					else
						e++;
				}
			}
		}
		cout << "Case " << i + 1 << ": " << e << " " << o << endl;
	}
}

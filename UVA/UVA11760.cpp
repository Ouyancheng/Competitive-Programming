#include<iostream>
#include<bitset>

using namespace std;

#define INF 999999999

int n,r,c,x,y,cc;
bitset<10000> row;
bitset<10000> col;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> r >> c >> n,r|c|n) {
		row.reset(); col.reset();
		for(int i = 0; i < n; i++) {
			cin >> x >> y;
			col[y] = row[x] = 1;
		}
		cin >> x >> y;
		cout << "Case " << ++cc << ": ";
		if((row[max(x-1,0)]|col[y])
			&(row[min(x+1,r-1)]|col[y])
			&(col[max(y-1,0)]|row[x])
			&(col[min(y+1,c-1)]|row[x])
			&(row[x]|col[y])) {
			cout << "Party time! Let's find a restaurant!";
		} else {
			cout << "Escaped again! More 2D grid problems!";
		}
		cout << endl;
	}
	return 0;
}
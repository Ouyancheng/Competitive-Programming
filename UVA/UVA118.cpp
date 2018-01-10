#include<bits/stdc++.h>

using namespace std;

int r, c, xr, yr;
bool d[55][55];
char dr;
string s;

bool can(int xd, int yd) {
	return xd >= 0 && xd <= r && yd >= 0 && yd <= c;
}

void rotate(char *dir, char cmd) {
	if(cmd == 'L') {
		if(*dir == 'N') {
			*dir = 'W';
		} else if(*dir == 'W') {
			*dir = 'S';
		} else if(*dir == 'S') {
			*dir = 'E';
		} else {
			*dir = 'N';
		}
	} else {
		if(*dir == 'N') {
			*dir = 'E';
		} else if(*dir == 'E') {
			*dir = 'S';
		} else if(*dir == 'S') {
			*dir = 'W';
		} else {
			*dir = 'N';
		}
	}
}

bool move(int * x, int * y, char * dir, char cmd) {
	if(cmd == 'L' || cmd == 'R') {
		rotate(dir, cmd);
		return 1;
	}
	int ox = *x, oy = *y;
	if(*dir == 'N') {
		*y = *y + 1;
	} else if(*dir == 'S') {
		*y = *y - 1;
	} else if(*dir == 'W') {
		*x = *x - 1;
	} else {
		*x = *x + 1;
	}
	if(can(*x, *y)) {
		return 1;
	}
	*x = ox;
	*y = oy;

	if(d[ox][oy]) {
		return 1;
	}
	d[ox][oy] = 1;
	return 0;
}

void work() {
	bool yes = 1;
	for(int i = 0; i < (int) s.length(); i++) {
		if(!move(&xr, &yr, &dr, s[i])) {
			yes = 0;
			break;
		}
	}
	cout << to_string(xr) + " " + to_string(yr) + " " + dr;
	cout << (yes ? "" : " LOST") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	while(cin >> xr >> yr >> dr) {
		cin >> s;
		work();
	}
	return 0;
}
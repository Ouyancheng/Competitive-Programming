#include<iostream>

using namespace std;

char mat[5][5];
char pat[5][5] = { {'#', '#' }, { '#','#' } };

bool can() {
	for(int i = 0; i < 4-2+1; i++) {
		for(int j = 0; j < 4-2+1; j++) {
			for(int x = 0; x < 2; x++) {
				for(int y = 0; y < 2; y++) {
					if(mat[i+x][j+y] != pat[x][y]) {
						goto next;
					}
				}
			}
			return true;
			next: ;
		}
	}
	return false;
}

void invert() {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(mat[i][j] == '.') {
				mat[i][j] = '#';
			} else {
				mat[i][j] = '.';
			}
		}
	}
}

bool chk() {
	if(can()) {
		return true;
	} else {
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if(mat[i][j] == '.') {
					mat[i][j] = '#';
					if(can()) {
						return true;
					} else {
						mat[i][j] = '.';
					}
				}
			}
		}
	}
	return false;
}

int main() {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> mat[i][j];
		}
	}
	bool c1 = chk();
	invert();
	bool c2 = chk();
	if(c1 || c2) {
		cout << "YES" << "\n";
	} else {
		cout << "NO" << "\n";
	}
	return 0;
}

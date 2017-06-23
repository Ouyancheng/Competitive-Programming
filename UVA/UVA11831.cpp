# include<iostream>
# include<sstream>

using namespace std;

# define R 0
# define C 1
# define N 0
# define E 1
# define S 2
# define W 3

int isValid(char grid[50000][100],int x,int y,int r,int c) {
	return r >= 0 && r < x && c >= 0 && c < y && grid[r][c] != '#';
}

int getVal(char c) {
	return c == 'N' ? 0 : c == 'L' ? 1 : c == 'S' ? 2 : c == 'O' ? 3 : 4;
}

int main(void) {
	int dir = N;
	char grid[50000][100];
	string tmp;
	stringstream cmd;
	int mv[4][2];
	mv[N][R] = -1;
	mv[N][C] = 0;
	mv[E][R] = 0;
	mv[E][C] = 1;
	mv[S][R] = 1;
	mv[S][C] = 0;
	mv[W][R] = 0;
	mv[W][C] = -1;

	while(true) {
		int rows = 0, cols = 0, ins = 0,rx = 0,ry = 0,st = 0;
		cin >> rows >> cols >> ins;
		if(rows == 0) {
			break;
		}
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				cin >> grid[i][j];
				if(grid[i][j] != '*' && grid[i][j] != '#' && grid[i][j] != '.') {
					rx = i;
					ry = j;
					dir = getVal(grid[i][j]);
					grid[i][j] = '.';
				} 
			}
		}
		getline(cin,tmp);
		getline(cin,tmp);
		cmd.str("");
		cmd << tmp;
		int cc = cmd.str().length();

		for(int i = 0; i < cc; i++) {
			char c = cmd.get();
			switch(c) {
				case 'D':
					dir = (dir + 1) % 4;
					break;
				case 'E':
					dir = (dir + 4 - 1) % 4;
					break;
				case 'F':
					if(isValid(grid,rows,cols,rx+mv[dir][R],ry+mv[dir][C])) {
						rx += mv[dir][R];
						ry += mv[dir][C];
						if(grid[rx][ry] == '*') {
							st++;
							grid[rx][ry] = '.';
						}
					}
			}
		}
		cout << st << endl;
	}
}

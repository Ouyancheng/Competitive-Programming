#include<iostream>
#include<vector>
#include<cassert>
#include<iomanip>

using namespace std;

#define MAT_MX 105

typedef int cell_type;
const int modulo = 1000000007;

class matrix {
	private:
		int rows, cols;
		cell_type buf[MAT_MX][MAT_MX];

		void copy(cell_type t[MAT_MX][MAT_MX], cell_type m[MAT_MX][MAT_MX], int r, int c) {
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					t[i][j] = m[i][j];
				}
			}
		}

		void self_mul(cell_type m[MAT_MX][MAT_MX]) {
			for(int i = 0; i < rows; i++) {
				for(int j = 0; j < cols; j++) {
					buf[i][j] = 0;
					for(int k = 0; k < cols; k++) {
						buf[i][j] = (0LL + buf[i][j] + ((1LL * mat[i][k] * m[k][j]) % modulo)) % modulo;
					}
				}
			}
			copy(mat,buf,rows,cols);
		}

		matrix(int r) {
			assert(r < MAT_MX);
			rows = cols = r;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < r; j++) {
					mat[i][j] = i == j;
				}
			}
		}

	public:
		cell_type mat[MAT_MX][MAT_MX];

		matrix(int r, int c, cell_type m[MAT_MX][MAT_MX]) {
			assert(r < MAT_MX && c < MAT_MX);
			rows = r;
			cols = c;
			copy(mat,m,rows,cols);
		}

		matrix operator *(const matrix &m) {
			assert(cols == m.rows);

			for(int i = 0; i < rows; i++) {
				for(int j = 0; j < m.cols; j++) {
					buf[i][j] = 0;
					for(int k = 0; k < cols; k++) {
						buf[i][j] = (0LL + buf[i][j] + ((1LL * mat[i][k] * m.mat[k][j]) % modulo)) % modulo;
					}
				}
			}
			return matrix(rows,m.cols,buf);
		}

		static matrix identity(int r) {
			return matrix(r);
		}

		matrix pow(long long n) {
			matrix res = identity(rows);
			matrix m(rows,cols,mat);

			for(int i = 0; (1LL << i) <= n; i++) {
				if(n & (1LL << i)) {
					res.self_mul(m.mat);
				}
				m.self_mul(m.mat);
			}
			return res;
		}

		void print() {
			for(int i = 0; i < rows; i++) {
				for(int j = 0; j < cols; j++) {	
					cout << right << mat[i][j] << " ";
				}
				cout << "\n";
			}
		}
};

int n, k;
cell_type v[MAT_MX][MAT_MX];
cell_type p[MAT_MX][MAT_MX];

int main() {
	cin >> n >> k;
	v[0][0] = 1;
	for(int i = 0; i < k+1; i++) {
		for(int j = 0; j < k+1; j++) {
			if(i == j) {
				p[i][j] = 1;
				if(i) {
					p[i-1][j] = 1;
				}
			}
		}
	}
	matrix pm = matrix(k+1,k+1,p).pow(n);
	matrix vm = matrix(1,k+1,v);
	matrix f = vm * pm;
	cout << f.mat[0][k] << "\n";
	return 0;
}

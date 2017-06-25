#include<iostream>

using namespace std;

int a[3][3];
int m[3][3];

bool can(int r,int c) {
  return (r >= 0 && c >= 0 && r < 3 && c < 3);
}

void make(int r,int c) {
    m[r][c] = !m[r][c];
	if(can(r-1,c)) m[r-1][c] = !m[r-1][c];
    if(can(r,c-1)) m[r][c-1] = !m[r][c-1];
  	if(can(r+1,c)) m[r+1][c] = !m[r+1][c];
  	if(can(r,c+1)) m[r][c+1] = !m[r][c+1];
}

int main(void) {
    for(int i = 0; i < 3; i++) {
    	for(int j = 0; j < 3; j++) {
        	cin >> a[i][j];
          	m[i][j] = 1;
        }
    }
    for(int i = 0; i < 3; i++) {
    	for(int j = 0; j < 3; j++) {
        	cin >> a[i][j];
            if(a[i][j]&1) make(i,j);
        }
    }  
    for(int i = 0; i < 3; i++) {
    	for(int j = 0; j < 3; j++) {
        	cout << m[i][j];
        }
      	cout << endl;
    }  
	return 0;
}
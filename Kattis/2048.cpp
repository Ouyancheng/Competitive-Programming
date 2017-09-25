#include<iostream>

using namespace std;

int m[6][6];
bool v[6][6];
int a;

bool can(int i,int j,int ii,int jj) {
    return ii >= 1 && ii <= 4 && jj >= 1 && jj <= 4 && !v[ii][jj] && (m[ii][jj] == 0 || m[i][j] == m[ii][jj]);
}

void move(int i,int j,int ii,int jj) {
    if(!can(i,j,ii,jj)) return;
    if(!v[i][j] && m[ii][jj] == m[i][j]) {
        if(m[i][j]) v[ii][jj] = 1;
        m[ii][jj] += m[i][j];
        m[i][j] = 0;
    } else if(m[ii][jj] == 0) {
        m[ii][jj] = m[i][j];
        m[i][j] = 0;
    }
}

void up(){
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            int k = i;
            while(can(k,j,k-1,j)) {
                move(k,j,k-1,j);
                k--;
            }
        }
    }
}

void down(){
    for(int i = 4; i >= 1; i--) {
        for(int j = 1; j <= 4; j++) {
            int k = i;
            while(can(k,j,k+1,j)) {
                move(k,j,k+1,j);
                k++;
            }
        }
    }
}

void right(){
    for(int i = 1; i <= 4; i++) {
        for(int j = 4; j >= 1; j--) {
            int k = j;
            while(can(i,k,i,k+1)) {
                move(i,k,i,k+1);
                k++;
            }
        }
    }
}

void left(){
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            int k = j;
            while(can(i,k,i,k-1)) {
                move(i,k,i,k-1);
                k--;
            }
        }
    }
}

void print(int a,int b) {
    for(int i = a; i < a + 4; i++) {
        for(int j = b; j < b + 4; j++) {
            cout << m[i][j];
            if(j < b+3) cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            cin >> m[i][j];
        }
    }
    cin >> a;
    if(a == 0) {
        left();
    } else if(a == 1) {
        up();
    } else if(a == 2) {
        right();
    } else {
        down();
    }
    print(1,1);
    return 0;
}
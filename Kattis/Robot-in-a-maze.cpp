#include<bits/stdc++.h>

using namespace std;

int gr, gc;

struct cell {
    int r, c, d, dir, cnt, pr, pc;
    
    cell() {}
    cell(int rr, int cc, int dd, int di, int co, int prr = -1, int pcc = -1) {
        r = rr, c = cc, d = dd, dir = di, cnt = co, pr = prr, pc = pcc;
    }    
};

const int maxn = 1e3 + 5;
const int oo = 1e9 + 7;

int t, n, m, D[maxn][maxn][4][3];
char M[maxn][maxn];
cell s;
const int dr[] = { -1, 1, 0, 0 }, dc[] = { 0, 0, -1, 1 };

bool can(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && M[r][c] != 'B';
}

int go() {
    queue<cell> pq;
    pq.push(s);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                D[i][j][k][0] = D[i][j][k][1] = D[i][j][k][2] = oo;
            }
        }
    }
    while((int) pq.size() > 0) {
        cell cur = pq.front();
        pq.pop();
        int cr = cur.r, cc = cur.c, d = cur.d, dir = cur.dir, cnt = cur.cnt, pr = cur.pr, pc = cur.pc;
        
        if(cnt == 2) {
            for(int i = 0; i < 4; i++) {
                int tr = cr+dr[i], tc = cc+dc[i]; 
                if(i != dir && can(tr, tc) && !(tr == pr && tc == pc) && d+1 < D[tr][tc][i][1]) {
                    if(tr == gr && tc == gc) return d+1;
                    D[tr][tc][i][1] = d+1;
                    pq.push({tr, tc, d+1, i, 1, cr, cc});
                }
            }
        } else {
            for(int i = 0; i < 4; i++) {
                int tr = cr+dr[i], tc = cc+dc[i];
                if(can(tr, tc) && !(tr == pr && tc == pc)) {
                    if(i == dir && d+1 < D[tr][tc][i][cnt+1]) {
                        if(tr == gr && tc == gc) return d+1;
                        D[tr][tc][i][cnt+1] = d+1;
                        pq.push({tr, tc, d+1, i, cnt+1, cr, cc});
                    } else if(d+1 < D[tr][tc][i][1]) {
                        if(tr == gr && tc == gc) return d+1;
                        D[tr][tc][i][1] = d+1;
                        pq.push({tr, tc, d+1, i, 1, cr, cc});
                    }                   
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> M[i][j];
                s = (M[i][j] == 'R') ? cell(i, j, 0, 0, 0) : s;
                gr = (M[i][j] == 'D') ? i : gr;
                gc = (M[i][j] == 'D') ? j : gc;
            }
        }
        cout << go() << "\n";
    }
    return 0;
}
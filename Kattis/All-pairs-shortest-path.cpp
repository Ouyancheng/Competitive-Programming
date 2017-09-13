#include<iostream>
#include<iomanip>

using namespace std;

int graph[180][180];
int n,m,q,a,b,c;
const int oo = 1e8;

void compute() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][k] != oo && graph[k][j] != oo && graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void detectCycle() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(graph[i][k] != oo && graph[k][j] != oo && graph[k][k] < 0) {
                    graph[i][j] = -oo;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m >> q) {
        if(!n && !m && !q) break;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) graph[i][j] = oo;
                else graph[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            if(c < graph[a][b])
                graph[a][b] = c;
        }
        compute();
        detectCycle();
        for(int i = 0; i < q; i++) {
            cin >> a >> b;
            if(graph[a][b] == oo) {
                cout << "Impossible" << "\n";
            } else if(graph[a][b] == -oo) {
                cout << "-Infinity" << "\n";
            } else {
                cout << graph[a][b] << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
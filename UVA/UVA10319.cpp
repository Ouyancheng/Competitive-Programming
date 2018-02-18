#include<bits/stdc++.h>

using namespace std;

#define MAX_N 1000

// variables for SCC algorithm
int scc_n, sccComp[MAX_N]; // *remember to intialize scc_n
stack<int> auxs;
vector<int> sccGraph[MAX_N], rsccGraph[MAX_N];
bool vis[MAX_N];

// user-defined variables
int t, n, m, a, b, c, d, s;

void revGraph(int u,vector<int> sccGraph[]) {
    vis[u] = 1;
    for(auto p : sccGraph[u]) {
        int v = p;
        rsccGraph[v].emplace_back(u);
        if(!vis[v]) revGraph(v,sccGraph);
    }
    auxs.emplace(u);
}

void decomposeSCC(int u,int par) {
    vis[u] = 1;
    sccComp[u] = par+1;
    for(auto p : rsccGraph[u]) {
        int v = p;
        if(!vis[v]) decomposeSCC(v,par);
    }
}

// function to compute Strongly Connected Components
// assumes that all SCC data structures have been reset
void computeSCC() {
    for(int i = 0; i < scc_n; i++) {
        if(!vis[i]) revGraph(i,sccGraph);
    }
    fill(vis,vis+scc_n,0);
    while(auxs.size() > 0) {
        if(!vis[auxs.top()])
            decomposeSCC(auxs.top(),auxs.top());
        auxs.pop();
    }
}

// call this function if applying SCC algorithm on multiple tests
void resetSCC() {
    fill(sccComp,sccComp+scc_n,0);
    fill(vis,vis+scc_n,0);
    for(int i = 0; i < scc_n; i++) {
        sccGraph[i].clear();
        rsccGraph[i].clear();
    }
}

void addEdge1(int a, int b) {
    sccGraph[a^1].emplace_back(b);
    sccGraph[b^1].emplace_back(a);
}

void addEdge2(int a, int b, int c, int d) {
    addEdge1(a, c);
    addEdge1(b, c);
    addEdge1(a, d);
    addEdge1(b, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> s;
        scc_n = (n + m) * 2;
        resetSCC();
        for(int i = 0; i < s; i++) {
            cin >> a >> b >> c >> d;
            a = a * 2 - 1, b = 2 * n + b * 2 - 1, c = c * 2 - 1, d = 2 * n + d * 2 - 1;
            if(a == c && b == d) {
                continue;
            }
            if(a > c && b < d) {
                addEdge2(a, d, b, c);
            } else if(a > c && b > d) {
                addEdge2(a^1, d, b, c^1);
            } else if(a < c && b < d) {
                addEdge2(b^1, c, a, d^1);
            } else if(a < c && b > d) {
                addEdge2(a^1, d^1, b^1, c^1);
            } else if(a == c) {
                if(b < d) {
                    addEdge1(a, a);
                } else {
                    addEdge1(a^1, a^1);
                }
            } else {
                if(a < c) {
                    addEdge1(b^1, b^1);
                } else {
                    addEdge1(b, b);
                }
            }
        }
        computeSCC();
        bool flag = 0;
        for(int i = 0; i < scc_n; i += 2) {
            if(sccComp[i] != 0 && sccComp[i] == sccComp[i^1]) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << "No";
        } else {
            cout << "Yes";
        }
        cout << "\n";
    }

    return 0;
}
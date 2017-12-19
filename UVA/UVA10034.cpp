#include<bits/stdc++.h>

using namespace std;

struct edge {
	int u, v;
	double w;
};

const int maxn = 105; 

int n, m, c, t, par[maxn];
double a, b, pa[maxn], pb[maxn];
vector<edge> E;

int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

void addEdge(int u, int v, double w) {
	E.push_back({u, v, w});
}

bool cmp(const edge &e1, const edge &e2) {
	return e1.w < e2.w;
}

double mst() {
	sort(E.begin(), E.end(), cmp);

	double cost = 0; int conn = 0;

	for(int i = 0; i < n; i++) {
		par[i] = i;
	}

	for(edge e : E) {
		int u = e.u, v = e.v; double w = e.w;
		int pu = find(u), pv = find(v);
		if(pu != pv) {
			par[pu] = pv;
			conn++;
			cost += w;
		}
		if(conn == n-1) {
			break;
		}
	}
	return cost;
}

double dist(int i, int j) {
	double da = pa[i] - pa[j], db = pb[i] - pb[j];
	return sqrt(da * da + db * db);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	cout << fixed;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n;
		E.clear();
		for(int j = 0; j < n; j++) {
			cin >> pa[j] >> pb[j];
		}
		for(int j = 0; j < n; j++) {
			for(int k = j+1; k < n; k++) {
				addEdge(j, k, dist(j, k));
			}
		}
		cout << mst() << "\n";
		if(i + 1 < t) {
			cout << "\n";
		}
	}
	return 0;
}

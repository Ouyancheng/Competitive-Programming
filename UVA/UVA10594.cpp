#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct Edge {
	int u, v;
	ll cap, flow, cost;
	Edge() {}
	Edge(int u, int v, ll cap, ll flow, ll c) : u(u), v(v), cap(cap), flow(flow), cost(c) {
	}
	Edge(int u1, int v1, ll cap1, ll c1) {
		u = u1;
		v = v1;
		cap = cap1;
		flow = 0;
		cost = c1;
	}
	bool operator<(const Edge& e) const {
		return cost > e.cost;
	}
};

struct MinCostMaxFlow {
	int V;
	vector<Edge> E;
	vector< vector<int> > augmented;
	vector< vector< pair<int,int> > > graph;
	vector<int> par;
	vector<ll> ddist, bdist, label;
	priority_queue<Edge> minhp;

	MinCostMaxFlow(int v) : V(v+2), E(0), augmented(v+2), graph(v), par(v+2), label(v+2), ddist(v+2), bdist(v+2) {
	}

	void addEdge(int u, int v, ll cap, ll cost) {
		E.emplace_back(Edge(u, v, cap, cost));
		augmented[u].emplace_back(E.size() - 1);
		E.emplace_back(Edge(v, u, 0, -cost));
		augmented[v].emplace_back(E.size() - 1);
	}

	void pre() {
		int src = V-2, sink = V-1;
		for(int i = 0; i < augmented.size()-2; i++) {
			if(label[i] > 0) {
				addEdge(src,i,label[i],0);
			} else if(label[i] < 0) {
				addEdge(i,sink,-label[i],0);
			}
		}
		/*
		for(int i = 0; i < E.size(); i+=2) {
			Edge e = E[i];
			cout << "(" << e.u+1 << ", " << e.v+1 << ", " << e.cap << ", " << e.flow << ", " << e.cost << ")" << "\n";
		}
		*/
	}

	bool bfsp(int src) {
		fill(bdist.begin(),bdist.end(),LLONG_MAX);
		bdist[src] = 0;
		bool anyrelax = false;
		for(int i = 0; i < V-1; i++) {
			anyrelax = false;
			for(int j = E.size()-2; j >= 0; j-=2) {
				Edge e = E[j];
				if(bdist[e.u] != LLONG_MAX && bdist[e.u] + e.cost < bdist[e.v]) {
					anyrelax = true;
					bdist[e.v] = bdist[e.u] + e.cost;
				}
			}
			if(!anyrelax) break;
		}
		for(int j = E.size()-2; j >= 0 ; j-=2) {
			Edge e = E[j];
			if(bdist[e.u] != LLONG_MAX && bdist[e.u] + e.cost < bdist[e.v]) {
				return false;
			}
		}
		return true;
	}

	bool diksp(int src,int dst) {
		minhp.emplace(Edge(src,src,1,0,0));
		fill(ddist.begin(),ddist.end(),LLONG_MAX);
		fill(par.begin(),par.end(),-1);

		ddist[src] = 0;
		while(minhp.size()) {
			Edge tmp = minhp.top();
			minhp.pop();

			ll w = tmp.cost; int u = tmp.v;

			if(ddist[u] == w) {
				vector<int> adj = augmented[u];
				for(int i = 0; i < adj.size(); i++) {
					Edge e = E[adj[i]];
					if(e.flow < e.cap && e.cost + ddist[u] < ddist[e.v]) {
						ddist[e.v] = e.cost + ddist[u];
						par[e.v] = adj[i];
						Edge p = Edge(u,e.v,e.cap,e.flow,ddist[e.v]);
						minhp.emplace(Edge(u,e.v,e.cap,e.flow,ddist[e.v]));
					}
				}
			}
		}
		return ddist[dst] != LLONG_MAX;
	}

	void reduce(vector<ll> &pot) {
		for(int i = 0; i < E.size(); i++) {
			Edge &fwd = E[i];
			Edge &bk = E[i^1];
			if(fwd.flow == fwd.cap) continue;
			fwd.cost = fwd.cost + pot[fwd.u] - pot[fwd.v];
			bk.cost = 0;
		}
	}

	pair<ll,ll> minCost(int src, int sink) {
		ll bcap = 0, flow = 0, ans = 0;
		pre();
		//if(!bfsp(src)) return -1;
		//reduce(bdist);
		while (diksp(src,sink)) {
			int v = sink;
			bcap = LLONG_MAX;
			//reduce(ddist);
			while (par[v] != -1) {
				bcap = min(bcap, E[par[v]].cap-E[par[v]].flow);
				v = E[par[v]].u;
			}
			v = sink;
			while (par[v] != -1) {
				E[par[v]].flow += bcap;
				E[par[v]^1].flow -= bcap;
				v = E[par[v]].u;
			}
			flow += bcap;
		}
		for(int i = 0; i < graph.size(); i++) {
			for(int j = 0; j < graph[i].size(); j++) {
				Edge e = E[graph[i][j].first];
				//cout << "(" << e.u+1 << ", " << e.v+1 << ", " << e.cap << ", " << e.flow << ", " << e.cost << ")" << " ";
				//cout << "[" << e.flow << "]" << "\n";
				ans = ans + graph[i][j].second * e.flow;
			}
		}
		return make_pair(ans,flow);
	}
};

struct Query {
	int a,b;
	ll c,d;
	Query(int a1,int b1,ll c1,ll d1): a(a1), b(b1), c(c1), d(d1) {}
};

int a, b, v, e;
ll c, d, k;
vector<Query> tmp; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> v >> e) {
		tmp.clear();
		MinCostMaxFlow ek(v);
		for(int i = 0; i < e; i++) {
			cin >> a >> b >> c;
			a--,b--;
			tmp.emplace_back(a,b,0,c);
			tmp.emplace_back(b,a,0,c);
		}
		cin >> d >> k >> ws;
		//unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		//shuffle(tmp.begin(),tmp.end(),default_random_engine(seed));
		for(int i = 0; i < tmp.size(); i++) {
			ek.graph[tmp[i].a].emplace_back(i*2,tmp[i].d);
			ek.addEdge(tmp[i].a,tmp[i].b,k,tmp[i].d);
		}
		ek.label[0] = d;
		ek.label[v-1] = -d;
/*
		for(int i = 0; i < v; i++) {
			cout << i+1 << ": ";
			for(int j = 0; j < ek.graph[i].size(); j++) {
				cout << ek.E[ek.graph[i][j].first].v+1 << " ";
			}
			cout << "\n";
		}
		*/
		pair<ll,ll> ans = ek.minCost(v,v+1);
		if(ans.second < d) {
			cout << "Impossible.";
		} else {
			cout << ans.first;
		}
		cout << "\n";
	}
	return 0;
}
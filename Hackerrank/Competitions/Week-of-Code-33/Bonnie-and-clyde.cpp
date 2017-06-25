// Li Hong Sheng Gabriel's Competitive Programming Template v2017.5
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>

//using namespace __gnu_pbds;
using namespace std;

#define len(s) (int) s.length()
#define sz(v) (int) v.size()
#define ll long long
#define mp make_pair
#define eb emplace_back
#define em emplace
#define pp pop()
#define p32 pair<int,int>
#define p64 pair<ll,ll>
#define pdd pair<double,double>
#define fi first
#define se second
#define repn(i,e) for(int i = 0; i < e; i++)
#define repsn(i,s,e) for(int i = s; i < e; i++)
#define rrepn(i,s) for(int i = s; i >= 0; i--)
#define rrepsn(i,s,e) for(int i = s; i >= e; i--)
#define v64 vector<ll>
#define v32 vector<int>
#define vp64 vector<p64>
#define vp32 vector<p32>
#define aprint(a,s) if(DRAFT) repn(k,s) cout << setw(3) << right << a[k] << " "; cout << endl
#define mprint(aa,rn,cn) if(DRAFT) repn(i,rn) { aprint(aa[i],cn); cout << endl; }
#define vprint(a) if(DRAFT) repn(k,sz(a)) cout << setw(3) << right << a[k] << " "; cout << endl
#define vvprint(a) if(DRAFT) repn(i,sz(a)) { cout << i << ": "; repn(j,sz(a[i])) { cout << a[i][j] << " "; } cout << endl; }
#define value(a) if(DRAFT) { cout << "DEBUG: The value of " << #a << " is " << a << endl; }
#define valuep(p) { if(DRAFT) cout << "( " << p.fi << ", " << p.se << " )" << endl; }
#define inf32 INT_MAX
#define inf64 LLONG_MAX
#define all(a) a.begin(),a.end()
#define UM unordered_map
#define US unordered_set
#define EPS 1e-10
#define breakl "\n"
#define MOD 1000000007

// Uncomment the include files, namespace and type to use
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> AVL;
// Usage for AvL:
// set functions, rank and select:
//select: cout<<*X.find_by_order(>=1)<<endl;
//rank: cout<<X.order_of_key(>=1)<<endl;

inline void scale(int x) {
    cout.precision(x);
    cout << fixed;
}

double dist(pdd x, pdd y) {
    return sqrt((x.fi - y.fi)*(x.fi - y.fi)+(x.se - y.se)*(x.se - y.se));
}
//int find(int x) { return (par[x]==x) ? x : par[x]=find(par[x]);}

inline void fastio(int debug) {
    if (debug) {
        cout << "DEBUGGING MODE..." << endl;
        freopen("input1", "r", stdin);
    } else {
        ios_base::sync_with_stdio(false), cin.tie(0);
    }
}

// End of Template

// user-defined macros
#define MAX_V 150010
#define LOG_V 19

int n, m, q, a, b;
int u, v, w;
// For UFDS
int upar[MAX_V];
// For LCA
int eui;
vector< pair<int, int> > graph[MAX_V];
int lvl[2 * MAX_V], vis[MAX_V], euler[2 * MAX_V], occ[MAX_V], ST[2 * MAX_V][LOG_V];
vector<int> can;

bool DRAFT = 1;

struct Graph {
    int n;
    vector<vector<int>> adj;

    Graph(int n) : n(n), adj(n) {
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int add_node() {
        adj.push_back({});
        return n++;
    }

    vector<int>& operator[](int u) {
        return adj[u];
    }
};

pair<Graph, pair< vector<int>, vector<int> > > biconnected_components(Graph &adj) {
    int n = adj.n;

    vector<int> num(n), low(n), art(n), stk;
    vector<vector<int>> comps;

    function<void(int, int, int&) > dfs = [&](int u, int p, int &t) {
        num[u] = low[u] = ++t;
        stk.push_back(u);

        for (int v : adj[u]) if (v != p) {
                if (!num[v]) {
                    dfs(v, u, t);
                    low[u] = min(low[u], low[v]);

                    if (low[v] >= num[u]) {
                        art[u] = (num[u] > 1 || num[v] > 2);

                        comps.push_back({u});
                        while (comps.back().back() != v)
                            comps.back().push_back(stk.back()), stk.pop_back();
                    }
                } else low[u] = min(low[u], num[v]);
            }
    };

    for (int u = 0, t; u < n; ++u)
        if (!num[u]) dfs(u, -1, t = 0);

    function < pair<Graph, pair< vector<int>, vector<int> > >() > build_tree = [&]() {
        Graph tree(0);
        vector<int> id(n);

        for (int u = 0; u < n; ++u)
            if (art[u]) id[u] = tree.add_node();

        for (auto &comp : comps) {
            int node = tree.add_node();
            for (int u : comp)
                if (!art[u]) id[u] = node;
                else tree.add_edge(node, id[u]);
        }
        return mp(tree, mp(art, id));
    };
    return build_tree();
}

void computeST() {
    for (int i = 0; i < eui; i++) {
        ST[i][0] = i;
    }
    for (int j = 1; (1 << j) <= eui; j++) {
        for (int i = 0; (i + (1 << j) - 1) < eui; i++) {
            if (lvl[ST[i][j - 1]] <= lvl[ST[i + (1 << (j - 1))][j - 1]]) {
                ST[i][j] = ST[i][j - 1];
                assert(ST[i][j] >= 0);
            } else {
                ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
                assert(ST[i][j] >= 0);
            }
        }
    }
}

void addLCAEdge(int u, int v, int w = 0) {
    graph[u].emplace_back(v, w);
    //graph[v].emplace_back(u,w);
}

int rmq(int a, int b) {
    int k = (int) log2(b - a + 1);
    if (lvl[ST[a][k]] <= lvl[ST[b - (1 << k) + 1][k]]) {
        return ST[a][k];
    } else {
        return ST[b - (1 << k) + 1][k];
    }
}

int lca(int a, int b) {
    int x = occ[a], y = occ[b];
    if (x > y) swap(x, y);
    return euler[rmq(x, y)];
}

int dist(int a, int b) {
    return lvl[occ[a]] + lvl[occ[b]] - 2 * lvl[occ[lca(a, b)]];
}

void dfslvl(int cur = 0, int depth = 1) {
    vis[cur] = 1;
    occ[cur] = eui;
    euler[eui] = cur;
    lvl[eui++] = depth;
    vector< pair<int, int> > adj = graph[cur];
    for (int i = 0; i < adj.size(); i++) {
        if (!vis[adj[i].fi]) {
            dfslvl(adj[i].fi, depth + 1);
            euler[eui] = cur;
            lvl[eui++] = depth;
        }
    }
}

void buildLCATree() {
    dfslvl();
    computeST();
}

int find(int x) {
    return upar[x] == x ? x : (upar[x] = find(upar[x]));
}

int main(void) {
    fastio(0);
    cin >> n >> m >> q;

    Graph g(n);

    repn(i, n) upar[i] = i;

    repn(i, m) {
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b);
        upar[find(a)] = find(b);
    }

    auto p = biconnected_components(g);

    Graph btree = p.fi;
    v32 art = p.se.fi, id = p.se.se;

    int s1 = btree.n;

    repn(i, s1) {
        int s2 = sz(btree[i]);

        repn(j, s2) {
            addLCAEdge(i, btree[i][j]);
        }
    }

    buildLCATree();

    repn(i, q) {
        cin >> u >> v >> w;
        u--, v--, w--;
        if (find(u) != find(w) || find(v) != find(w) || (u == v && v != w)) {
            cout << "NO" << breakl;
        } else {
            int dist_uv = dist(id[u], id[v]);
            int dist_uw = dist(id[u], id[w]);
            int dist_vw = dist(id[v], id[w]);

            int add = 2 * art[w];

            if (dist_uv + add >= dist_uw + dist_vw) {
                cout << "YES" << breakl;
            } else {
                cout << "NO" << breakl;
            }
        }
    }
    return 0;
}
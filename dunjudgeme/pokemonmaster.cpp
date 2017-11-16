#include<iostream>
#include<vector>
#include<algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAX_RC 50010
#define LOG_RC 16
#define SSZ 131072

typedef tree<
int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	AVL;

	struct Cell {
		int L, P, i;
	};

int r,c,q,t,pa,pb,pc,pd,tot,logt;
Cell cells[MAX_RC];
int A[MAX_RC], par[MAX_RC], in[MAX_RC], out[MAX_RC], lorder[MAX_RC], corder[MAX_RC];
AVL segTree[SSZ], colors[MAX_RC];
vector<int> G[MAX_RC];
int ST[MAX_RC][LOG_RC];

int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

bool cmp(const int i,const int j) {
	return cells[i].L < cells[j].L;
}

void read(bool t=1) {
	for(int i = 0; i < tot; i++) {
		if(t) {
			scanf("%d",&cells[i].L);
		} else {
			scanf("%d",&cells[i].P);
		}
		cells[i].i = i;
		lorder[i] = i;
	}
	if(t) read(0);
}

bool can(int i1,int i2) {
	if(i2 < 0 || i2 >= tot) return 0;
	int i = i2 / c, j = i2 % c, x = i1 / c, y = i1 % c;
	return (i == x && abs(j-y) == 1) || (j == y && abs(i-x) == 1);
}

void link(int i1,int i2) {
	if(!can(i1,i2) || cmp(i1,i2)) return;
	if(find(i2) != i1) G[i1].push_back(find(i2));
	par[find(i2)] = i1;
}

void ufds() {
	sort(lorder,lorder+tot,cmp);
	for(int i = 0; i < tot; i++) {
		Cell cur = cells[lorder[i]];
		link(cur.i,cur.i-c);
		link(cur.i,cur.i+c);
		link(cur.i,cur.i-1);
		link(cur.i,cur.i+1);
	}
}

void dfs(int cur,int p=-1,int h=1) {
	out[cur] = in[cur] = t++;
	corder[in[cur]] = cur;
	ST[cur][0] = p;
	for(int i = 1; (1 << i) < h; i++) {
		ST[cur][i] = ST[ST[cur][i-1]][i-1];
	}
	for(auto nei : G[cur]) {
		if(nei != p) {
			dfs(nei,cur,h+1);
			out[cur] = t-1;
		}
	}
}

void pre() {
	int M[MAX_RC];
	fill(M,M+MAX_RC,-1);
	for(int i = tot-1; i >= 0; i--) {
		if(M[cells[corder[i]].P] != -1) {
			A[i] = M[cells[corder[i]].P];
		} else {
			A[i] = i + tot;
		}
		colors[cells[corder[i]].P].insert(i);
		M[cells[corder[i]].P] = i;
	}
}

void buildMSTree(int r,int lo,int hi) {
	for(int i = lo; i <= hi; i++) {
		segTree[r].insert(A[i]);
	}
	if(lo == hi) return;
	buildMSTree(r<<1,lo,(lo+hi)>>1);
	buildMSTree((r<<1)|1,((lo+hi)>>1)+1,hi);
}

void addMSTree(int r,int lo,int hi,int idx,int v) {
	if(idx < lo || idx > hi) return;
	if(idx >= lo && idx <= hi) {
		segTree[r].insert(v);
	}
	if(lo == hi) return;
	int mid = (lo + hi) >> 1;
	addMSTree(r<<1,lo,mid,idx,v);
	addMSTree((r<<1)|1,mid+1,hi,idx,v);
}

void delMSTree(int r,int lo,int hi,int idx,int v) {
	if(idx < lo || idx > hi) return;
	if(idx >= lo && idx <= hi) {
		segTree[r].erase(v);
	}
	if(lo == hi) return;
	int mid = (lo + hi) >> 1;
	delMSTree(r<<1,lo,mid,idx,v);
	delMSTree((r<<1)|1,mid+1,hi,idx,v);
}

int queryMSTree(int r,int lo,int hi,int a,int b,int x) {
	if(lo > b || hi < a) {
		return 0;
	} else if(a <= lo && b >= hi) {
		bool con = (segTree[r].find(x) != segTree[r].end());
		if(!con) segTree[r].insert(x);
		int ans = (int) segTree[r].size() - segTree[r].order_of_key(x) - 1;
		if(!con) segTree[r].erase(x);
		return ans;
	} else {
		int mid = (lo+hi)>>1;
		return queryMSTree(r<<1,lo,mid,a,b,x)+queryMSTree((r<<1)|1,mid+1,hi,a,b,x);
	}
}

void update(int i,int j,int nc) {
	int idx = i * c + j;
	int oc = cells[idx].P, ov = A[in[idx]], ov2 = -1, ov3 = -1;

	if(oc == nc) return;

	auto fw = colors[nc].upper_bound(in[idx]);
	A[in[idx]] = fw == colors[nc].end() ? in[idx]+tot : *fw;

	auto bk = colors[oc].lower_bound(in[idx]);

	if(bk != colors[oc].begin()) {
		bk--;
		ov2 = A[*bk];
		auto bkf = colors[oc].upper_bound(in[idx]);
		A[*bk] = bkf == colors[oc].end() ? *bk+tot : *bkf;
	}

	auto nbk = colors[nc].upper_bound(in[idx]);

	if(nbk != colors[nc].begin()) {
		nbk--;
		ov3 = A[*nbk];
		A[*nbk] = in[idx];
	}

	colors[oc].erase(in[idx]);
	colors[nc].insert(in[idx]);
	cells[idx].P = nc;

	delMSTree(1,0,tot-1,in[idx],ov);
	if(ov2 != -1) delMSTree(1,0,tot-1,*bk,ov2);
	if(ov3 != -1) delMSTree(1,0,tot-1,*nbk,ov3);

	addMSTree(1,0,tot-1,in[idx],A[in[idx]]);
	if(ov2 != -1) addMSTree(1,0,tot-1,*bk,A[*bk]);
	if(ov3 != -1) addMSTree(1,0,tot-1,*nbk,A[*nbk]);
}


int top(int i,int j,int k) {
	int cur = i*c+j;
	if(cells[cur].L > k) return -1;
	for(int i = logt; i >= 0; i--) {
		if(ST[cur][i] != -1 && cells[ST[cur][i]].L <= k) {
			cur = ST[cur][i];
		}
	}
	return cur;
}

int main() {
	int root = -1, omx = 0;

	scanf("%d %d %d",&r,&c,&q);
	tot = r * c;
	logt = (int) log2(tot);
	read();

	for(int i = 0; i < tot; i++) {
		if(omx < cells[i].L) {
			root = i;
			omx = cells[i].L;
		}
		par[i] = i;
		for(int j = 0; (1 << j) < tot; j++) {
			ST[i][j] = -1;
		}
	}
	ufds();
	dfs(root);
	pre();
	buildMSTree(1,0,tot-1);

	for(int i = 0; i < q; i++) {
		cin >> pa >> pb >> pc >> pd;
		--pb, --pc;
		swap(pb,pc);
		if(pa == 1) {
			update(pb,pc,pd);
		} else {
			int root = top(pb,pc,pd);
			if(root == -1) {
				printf("0");
			} else {
				int idx = pb * c + pc;
				printf("%d",queryMSTree(1,0,tot-1,in[root],out[root],out[root]));
			}
			printf("\n");
		}
	}
	return 0;
}

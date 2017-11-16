#include<iostream>
#include<unordered_map>
#include<utility>

using namespace std;

struct result {
	bool can;
	int i1,i2,i3,i4;
};

struct arr {
	int * head;
	int sz;

	arr(int * h,int s) {
		head = h;
		sz = s;
	}
};

int an,bn,cn,dn;
int a[505],b[505],c[505],d[505],ans[4];
bool use[(int)1e7+5];
unordered_map<int,pair<int,int>> m1;

result pairing(arr aa,arr bb,arr cc,arr dd) {
	m1.clear();
	result rs;
	rs.can = 0;

	for(int i = 0; i < aa.sz; i++) {
		for(int j = 0; j < bb.sz; j++) {
			m1[aa.head[i]+bb.head[j]] = make_pair(i,j);
		}
	}

	for(int i = 0; i < cc.sz; i++) {
		for(int j = 0; j < dd.sz; j++) {
			auto cur = m1.find(-(cc.head[i]+dd.head[j]));
			if(cur != m1.end()) {
				rs.can = 1;
				rs.i1 = cur->second.first;
				rs.i2 = cur->second.second;
				rs.i3 = i;
				rs.i4 = j;
				return rs;
			}
		}
	}
	return rs;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	m1.reserve(1<<14);
	cin >> an >> bn >> cn >> dn;
	for(int i = 0; i < an; i++) cin >> a[i];
	for(int i = 0; i < bn; i++) cin >> b[i];
	for(int i = 0; i < cn; i++) cin >> c[i];
	for(int i = 0; i < dn; i++) cin >> d[i];

	result rs;
	arr ar[] = { arr(a,an), arr(b,bn), arr(c,cn), arr(d,dn) };
	int * aa, * bb, * cc, *dd;
	for(int i = 0; i < 4; i++) {
		for(int j = i+1, k, m; j < 4; j++) {
			for(k = 0; k == i || k == j; k++);
			for(m = 0; m == i || m == j || m == k; m++);
			rs = pairing(ar[i],ar[j],ar[k],ar[m]);
			ans[i] = ar[i].head[rs.i1];
			ans[j] = ar[j].head[rs.i2];
			ans[k] = ar[k].head[rs.i3];
			ans[m] = ar[m].head[rs.i4];
			if(rs.can) break;
		}
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
	return 0;
}
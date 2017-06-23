#include<cstdio>
#include<cstring>
using namespace std;

void subtract(int d,int i,int f[],int N) {
	int c = i;
	while(c < N) {
		f[c] -= d;
		c += c & -c;
	}
}

int query(int i, int f[]) {
	int c = i;
	int ans = 0;
	while(c >= 1) {
		ans += f[c];
		c -= c & -c;
	}
	return ans;
}

void add(int d,int i,int f[],int N) {
	int c = i;
	while(c < N) {
		f[c] += d;
		c += c & -c;
	}
}

int sets(int f[],int N,int occ[]) {
	int ans = 0;
	int l = 1;
	int r = N-1;

	while(l <= r) {
		int mid = (l+r)/2;
		if(query(mid,f) == mid) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}

int main(void) {
	int cc = 0, a = 0, b = 0, maxc = 1000000 + 1;
	scanf("%d",&cc);
	int fenwick[maxc];
	int occ[maxc];
	memset(fenwick,0,maxc);
	memset(occ,0,maxc);

	for(int i = 0; i < cc; i++) {
		scanf("%d %d",&a,&b);
		switch(a) {
			case 1:
			    if(b <= 1000000) {
					occ[b]++;
					if(occ[b] == 1) {
						add(1, b, fenwick, maxc);
					}
				}
				printf("%d\n",sets(fenwick,maxc,occ));
				break;
			case 2:
				if(b <= 1000000) {
					if(occ[b] > 0) {
						occ[b]--;
						if(occ[b] == 0) subtract(1, b, fenwick, maxc);
					}
				}
				printf("%d\n",sets(fenwick,maxc,occ));
		}
	}
	return 0;
}
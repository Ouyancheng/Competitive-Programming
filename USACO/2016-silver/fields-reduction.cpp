#include<cstdio>
#include<algorithm>
#include<cmath>

#define MAX_N 50005

using namespace std;

int L[MAX_N],  R[MAX_N], x[MAX_N], y[MAX_N];
const int oo = 2e9;
int a,b,n,ans = oo;

bool cmpx(const int p1,const int p2) {
	return L[p1] < L[p2];
}

bool cmpy(const int p1,const int p2) {
	return R[p1] < R[p2];
}

int chk(int lx,int hx,int ly,int hy) {
	int trim = 0, a = L[lx], b = L[hx], c = R[ly], d = R[hy];
	for(int i = 0; i < n; i++) {
		if(L[i] < a || L[i] > b || R[i] < c || R[i] > d) {
			trim++;
			if(trim > 3) break;
		}
	}
	return trim <= 3 ? (b - a) * (d - c) : oo;
}

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d",&a,&b);
		L[i] = a, R[i] = b;
		x[i] = y[i] = i;
	}
	sort(x,x+n,cmpx);
	sort(y,y+n,cmpy);
	for(int i = 0; i < min(4,n); i++) {
		for(int j = n-1; j >= max(n-4,0); j--) {
			for(int k = 0; k < min(4,n); k++) {
				for(int l = n-1; l >= max(n-4,0); l--) {
					ans = min(ans,chk(x[i],x[j],y[k],y[l]));
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

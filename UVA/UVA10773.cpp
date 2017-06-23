#include<cstdio>
#include<cmath>

using namespace std;

int n;
double d,v,u;
double f,s;

int main(void) {
	scanf("%d",&n);

	for(int i = 1; i <= n; i++) {
		scanf("%lf%lf%lf",&d,&v,&u);
		if(u == 0 || u*u - v*v <= 0) {
			printf("Case %d: %s\n",i,"can't determine");
			continue;
		}
		f = d/u;
		s = d/sqrt(u*u - v*v);
		if(f == s) {
			printf("Case %d: %s\n",i,"can't determine");
		} else {
			printf("Case %d: %.3lf\n",i,abs(f-s));
		}
	}
	return 0;
}
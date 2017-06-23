#include<cstdio>
#include<cmath>

using namespace std;

int p, q, r, s, t, u;

inline double solve(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u;
}

int main(void) {
	while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF) {
		double lo = 0, hi = 1, mid;
		if(solve(0) * solve(1) > 0) {
			printf("No solution\n");
			continue;
		}
		while(hi - lo > 1e-9) {
			mid = (lo + hi)/2;
			if(solve(mid) * solve(0) <= 0) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		printf("%.4lf\n",mid);
	}
	return 0;
}

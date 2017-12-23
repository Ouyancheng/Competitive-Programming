#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 5e5 + 5;

int n, m1, m2;
long long a[maxn];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		if(a[i] > a[m1]) {
			m2 = m1;
			m1 = i;
		} else if(a[i] > a[m2]) {
			m2 = i;
		}
	}
	if(m1 > m2) {
		swap(m1, m2);
	}
	printf("%d %d\n", m1+1, m2+1);
	return 0;
}

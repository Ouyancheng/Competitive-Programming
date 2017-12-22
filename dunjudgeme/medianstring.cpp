#include<cstdio>

using namespace std;

int n;
long long a;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a);
		if(i == n/2) {
			printf("%lld\n", a);
			return 0;
		}
	}
}

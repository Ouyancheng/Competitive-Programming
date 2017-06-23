#include<cstdio>

using namespace std;

int v, t;

int main(void) {
	while(scanf("%d %d",&v,&t) != EOF) {
		printf("%d\n",v * t * 2);
	}
	return 0;
}
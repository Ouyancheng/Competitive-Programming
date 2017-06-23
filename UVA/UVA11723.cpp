#include<cstdio>

using namespace std;

int n,r,c;

int main(void) {
	while(scanf("%d %d",&n,&r) != EOF && (n | r)) {
		c++;
		if(n > r * 27) {
			printf("Case %d: impossible\n",c);
		} else {
			for(int i = 1; i <= 27; i++) {
				if(n <= r * i) {
					printf("Case %d: %d\n",c,i-1);
					break;
				}
			}
		}
	}
	return 0;
}
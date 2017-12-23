#include<cstdio>
#include<algorithm>

using namespace std;

int n, t;

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if(n % 3) {
			printf("JELLY");
		} else {
			printf("JACK");
		}
		printf("\n");
	}
	return 0;
}
#include<cstdio>

using namespace std;

int n, a[2005], lo, hi, win = 2005, ans, com;

int gcd(int a, int b) {
	return b ? gcd(b,a%b) : a;
}

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		if(i == 0) {
			com == a[i];
		}
		com = gcd(com, a[i]);
	}
	if(com != 1) {
		printf("%d\n", -1);
	} else {
		for(int i = 0; i < n; i++) {
			com = a[i];
			for(int j = i; j < n; j++) {
				com = gcd(com, a[j]);
				if(com == 1 && j - i + 1 < win) {
					lo = i, hi = j;
					win = j - i + 1;
					break;
				}
			}
		}
		ans = 2 * (win - 1); 
		for(int i = lo-1; i >= 0; i--) {
			if(a[i] != 1) {
				ans++;
			}
		}
		for(int i = hi+1; i < n; i++) {
			if(a[i] != 1) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
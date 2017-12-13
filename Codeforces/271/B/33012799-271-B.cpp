#include<iostream>
#include<cmath>

using namespace std;

#define MAX_N 100100 // Used by all sieve functions. If using ssieve(a,b) or ssieve(n),
// define as >= ceil(sqrt(MAX_INPUT)) else define as >= MAX_INPUT

unsigned int prime[MAX_N/64+1];
int near[MAX_N+5], primes[MAX_N+5], ni, pi, n, m, ans = (int) 1e9;
int mat[505][505];

#define setbit(x,a) (a[x>>6])|=(1<<((x>>1)&31))
#define chkbit(x,a) (a[x>>6])&(1<<((x>>1)&31))
#define isprime(x) (!(x!=2&&(!(x&1)||chkbit(x,prime)))) // this macro is used for sieve(n) only!

void sieve(int n) {
	setbit(1,prime);
	for(int i = 3; i*i <= n; i+=2) {
		if(chkbit(i,prime)) continue;
		for(int j = i*i, k = i<<1; j <= n; j+=k) {
			setbit(j,prime);
		}
	}
}

void calc() {
	for(int i = 0; i < pi; i++) {
		near[primes[i]] = primes[i];
		for(int j = primes[i]-1; j >= 0 && !isprime(j); j--) {
			near[j] = primes[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve(MAX_N);
	primes[pi++] = 2;
	for(int i = 3; i <= MAX_N; i+=2) {
		if(isprime(i)) {
			primes[pi++] = i;
		}
	}
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!isprime(mat[i][j])) {
				goto loop;
			}
		}
		cout << 0 << "\n";
		return 0;
loop: ;
	}
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(!isprime(mat[i][j])) {
				goto loop2;
			}
		}
		cout << 0 << "\n";
		return 0;
loop2: ;
	}
	calc();
	for(int i = 0; i < n; i++) {
		int tmp  = 0;
		for(int j = 0; j < m; j++) {
			tmp += (int) abs(near[mat[i][j]] - mat[i][j]);
		}
		ans = min(ans,tmp);
	}

	for(int j = 0; j < m; j++) {
		int tmp  = 0;
		for(int i = 0; i < n; i++) {
			tmp += (int) abs(near[mat[i][j]] - mat[i][j]);
		}
		ans = min(ans,tmp);
	}
	cout << ans << "\n";
	return 0;
}

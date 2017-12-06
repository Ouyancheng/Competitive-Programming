#include<iostream>

using namespace std;

typedef long long ll;

int n;

#define MAX_N (int(1e6+5)) // Used by all sieve functions. If using ssieve(a,b) or ssieve(n), 
					// define as >= ceil(sqrt(MAX_INPUT)) else define as >= MAX_INPUT

unsigned int prime[MAX_N/64+1];
int primes[79000], pi;
ll a;

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

void work() {
	sieve(1e6);
	primes[pi++] = 2;
	for(int i = 3; i < 1e6; i+=2) {
		if(isprime(i)) {
			primes[pi++] = i;	
		}
	}
}

bool query(ll k) {
	int lo = 0, hi = pi - 1;
	while(lo <= hi) {
		int mid = (lo + hi)/2;
		if(k > 1LL*primes[mid]*primes[mid]) {
			lo = mid + 1;
		} else if(k < 1LL*primes[mid]*primes[mid]) {
			hi = mid - 1;
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	work();
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(query(a)) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		cout << "\n";
	}
	return 0;
}
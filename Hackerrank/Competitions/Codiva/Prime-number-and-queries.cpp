#include<bits/stdc++.h>

using namespace std;

#define MAX_N ((int) 1e6)
#define setbit(x,a) (a[x>>6])|=(1<<((x>>1)&31))
#define chkbit(x,a) (a[x>>6])&(1<<((x>>1)&31))
#define isprime(x) (!(x!=2&&(!(x&1)||chkbit(x,prime)))) // this macro is used for sieve(n) only!

unsigned int prime[MAX_N/64+1];
int q,a,b,pi;
int primes[(int) 8e4];

// naive sieve of erasthostenes
// Pre-condition: array of size n+1 where n is the given parameter
// n: upper bound value for sieve
// Post-condition:  calculates all the prime numbers in <= n
// Prime numbers are marked as 1 in the array "prime"
void sieve(int n) {
	setbit(1,prime);
	for(int i = 3; i*i <= n; i+=2) {
		if(chkbit(i,prime)) continue;
		for(int j = i*i, k = i<<1; j <= n; j+=k) {
			setbit(j,prime);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve((int)1e6);
    primes[pi++] = 2;
    for(int i = 3; i < (int) 1e6; i+=2) {
        if(isprime(i)) primes[pi++] = i;
    }
    cin >> q;
    while(q--) {
        cin >> a >> b;
        auto lo = lower_bound(primes,primes+pi,a);
        auto hi = upper_bound(primes,primes+pi,b);
        hi--;
        if(lo >= hi) {
            cout << 0;
        } else {
            cout << *hi - *lo;
        }
        cout << "\n";
    }
    return 0;
}

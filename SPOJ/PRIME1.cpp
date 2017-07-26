#include<iostream>
#include<cmath>
#include<list>
#include<cassert>
 
using namespace std;
 
#define MAX_N 32000
#define MAX_R 100000
 
unsigned int prime[MAX_N/64+1];
unsigned int segment[MAX_R/64+1];
 
#define setbit(x,a) (a[x>>6])|=(1<<((x>>1)&31))
#define chkbit(x,a) (a[x>>6])&(1<<((x>>1)&31))
#define isprime(x) !(x!=2&&(!(x&1)||chkbit(x,prime)))
 
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
 
int ssieve(int a,int b) {
	list<int> primes;
	int off = a - (a&1), cnt = 0;
	int sn = floor(sqrt(b));
	sieve(sn);
	for(int i = 0; i <= ((b-off)>>6); i++) {
		segment[i] = 0;
	}
	for(int i = 1; i <= sn; i+=2) {
		if(isprime(i)) {
			primes.push_back(i);
		}
	}
	for(auto p : primes) {
		int mul = (int)ceil(1.0*a/p)*p;
		if(!(mul&1)) mul += p;
		for(int i = mul, k = p<<1; i <= b; i+=k) {
			if(i == p) continue;
			setbit((i-off),segment);
		}
	}
	/*
	cnt += (a <= 2 && b >= 2);
	for(int i = max(3,a+!(a&1)); i <= b; i+=2) {
		if(!(chkbit((i-off),segment))) {
			cnt++;
		}
	}
	*/
	return cnt;
}
 
int t,a,b;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> a >> b;
		ssieve(a,b);
		int off = a - (a&1);
		if(a <= 2 && b >= 2) cout << 2 << "\n";
		for(int i = max(3,a+!(a&1)); i <= b; i+=2) {
			if((chkbit((i-off),segment))) continue;
			cout << i << "\n";
		}
		if(t >= 1) {
			cout << "\n";
		}
	}
	return 0;
} 
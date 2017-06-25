#include<bits/stdc++.h>

using namespace std;

#define limit 200001
#define ii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vii vector<ii>
#define pb push_back


const int MOD = 1e9 + 7;

int h,w,n,a,b;
int fact[limit];
int invfact[limit];
vii cells;
long long dp[2001];

// Pre-condition:
// a: integer value for calculating power
// b: non -ve integer value that represents exponent
// MOD: integer modulo value
// Post-condition: Returns the value of a^b % MOD
// Time-complexity: O(logb)
int powMod(int a, int b, int MOD) {
    if (b == 0) return 1;
    long long res = powMod(a, b / 2, MOD);
    res = (res * res) % MOD;
    return (int) ((b & 1) ? a * res % MOD : res);
}

// Pre-condition: MOD must be a prime
// a: non -ve integer value for calculating factorial
// MOD: non -ve integer modulo value
// Post-condition: Returns x % MOD which satisfies ax = 1 % MOD
// Time-complexity: O(logMOD)
int invMod(int a, int MOD) {
    return powMod(a, MOD - 2, MOD) % MOD;
}

// Pre-condition: array fact must exist and have a+1 space
// a: non -ve integer value for calculating factorial
// MOD: non -ve integer modulo value
// Post-condition: Precalculates factorial % MOD for integers up to value of a
// Time-complexity: O(a)
void factMod(int a, int MOD) {
    int cnt = 1;
    fact[0] = 1;
    while (cnt <= a) fact[cnt] = (int)((long long) fact[cnt-1] * cnt % MOD), cnt++;
}

// Pre-condition:
// arrays fact and invfact must be precalcuated up to value of n
// n: non -ve integer (< 2^31)
// r: non -ve integer (< 2^31)
// MOD: integer-type modulo value
// Post-condition: returns the answer for C(n,r) % MOD
// Time-complexity: O(1)
int ncrMod(int n, int r, int MOD) {
    if (r == n || r == 0) return 1;
    if (r > n) return 0;
    return ((long long) fact[n] * invfact[n-r] % MOD * invfact[r]) % MOD;
}

// Pre-codition:
// n: +ve integer
// invMod function must exist
// fact array must also be preculated up to value of n
// invfact array must exist and have n+1 space
// Post-condition:
// Pre-calculates factorial integers in [0,n]
// Pre-calculates inverse modulo for integers in [1,n]
// Time-complexity: O(nlogMOD)
void calc(int n) {
    factMod(n - 1, MOD);
    for (int i = 1; i <= n; i++) {
        invfact[i] = invMod(fact[i], MOD);
    }
}

int main(void) {
	calc(limit-1);
	scanf("%d %d %d", &h, &w, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d",&a,&b);
		cells.pb(mp(a,b));
	}
	cells.pb(mp(h,w));
	sort(cells.begin(),cells.end());
	for(int i = 0; i <= n; i++) {
		dp[i] = ncrMod(cells[i].fi-1+cells[i].se-1,cells[i].fi-1,MOD);
		for(int j = 0; j < i; j++) {
			if(cells[j].fi <= cells[i].fi && cells[j].se <= cells[i].se)
				dp[i] = (dp[i] + MOD - dp[j] *
					ncrMod(cells[i].fi-cells[j].fi+cells[i].se-cells[j].se,cells[i].fi-cells[j].fi,MOD) % MOD) % MOD;
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}
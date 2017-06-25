#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, I;
int par[100001], rk[100001];
int find(int x) { return (par[x]==x ? x : par[x] = find(par[x])); }

int main(void) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin >> N;
    fill_n(rk,N,1);

    long long ans = 0;
    int other = 0;
    for(int i = 0; i < N; i++) par[i] = i;
    cin >> I;
    for(int i = 0; i < I; i++) {
        cin >> a >> b;
        if(find(a)!=find(b)) {
            rk[find(a)] += rk[find(b)];
            rk[find(b)] = 0;
            par[find(b)] = find(a);
        }
    }
    for(int i = 0; i < N; i++) {
        ans += other*rk[find(i)];
        other += rk[find(i)];
        rk[find(i)]=0;
    }
    cout << ans << "\n";
    return 0;
}

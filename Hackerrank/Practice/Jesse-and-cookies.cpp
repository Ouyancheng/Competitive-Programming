#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n,k;
multiset<long long> low;
long long arr[1000000];
long long fi,se,ops;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) {
        scanf("%lld",&arr[i]);
        low.insert(arr[i]);
    }
    while(low.size() >= 2 && *low.begin() < k) {
        fi = *(low.begin());
        low.erase(low.begin());
        se = *(low.begin());
        low.erase(low.begin());
        low.insert(fi + 2 * se);
        ops++;
    }
    if(*low.begin() < k) {
        printf("%d\n",-1);
    } else {
        printf("%lld\n",ops);
    }
    return 0;
}

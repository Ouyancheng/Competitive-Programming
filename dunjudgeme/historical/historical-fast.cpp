#include <bits/stdc++.h>

// Faster solution for "historical".
// Time-complexity is O(QlogQ + (N+Q)sqrt(N))

using namespace std;
#define mp make_pair
typedef long long ll;
typedef pair<ll, int> pli;
const int MAXN = 100005;
int N, Q, X[MAXN], A[MAXN], B[MAXN], o[MAXN], sq, p, P[MAXN], C[MAXN];
map<int, int> m;
ll ans[MAXN];
bool cmp (int x, int y) { // custom comparator to perform sqrt decomposition
    if ((A[x]-1)/sq == (A[y]-1)/sq) return B[x] < B[y];
    return A[x] < A[y]; 
}
int main () {
    scanf("%d%d", &N, &Q);
    sq = sqrt(N);
    for (int i = 0; i < N; ++i) scanf("%d", &X[i]), m[X[i]] = 0; // coordinate compression
    for (auto it = m.begin(); it != m.end(); ++it, ++p) it->second = p; // assign ranks
    for (int i = 0; i < N; ++i) P[i] = m[X[i]]; // Compress each element by storing its rank into P
    for (int i = 0; i < Q; ++i) scanf("%d%d", &A[i], &B[i]);
    for (int i = 0; i < Q; ++i) o[i] = i; // Assign numbers to the queries (to maintain actual ordering)
    sort(o, o+Q, cmp); // segment the queries based on their left and right bound
    int prev = -1;
    ll prev_ans = -1;
    for (int i = 0, r = 0; i < Q; ++i) {
        int a = A[o[i]]-1, b = B[o[i]]-1;
        if (prev != a/sq + 1) {
            prev = a/sq + 1;
            prev_ans = 0;
            memset(C, 0, sizeof C);
            r = prev*sq; // get start of next bucket
        }
        for (; r <= b; ++r) // assumes that b is in different bucket
            prev_ans = max( (ll) ++C[P[r]]*X[r], prev_ans); // update the max product as window expands to the right
        ans[o[i]] = prev_ans;
        for (int l = a; l < min(b+1, prev*sq); ++l) // either brute force within same bucket or search until next bucket only
            ans[o[i]] = max( (ll) ++C[P[l]]*X[l], ans[o[i]]);
        for (int l = a; l < min(b+1, prev*sq); ++l) --C[P[l]]; // delete all elements at least until next bucket/b
    }
    for (int i = 0; i < Q; ++i) printf("%lld\n", ans[i]);
}
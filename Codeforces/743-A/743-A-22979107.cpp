#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
#include <set>
#include <cstdlib>
#include <utility>
#include <queue>

using namespace std;

#define ll long long
#define valid(r,c,rn,cn) (r >= 0 && c >= 0 && r < rn && c < cn)
#define ntc(a) (char) (a + 'A')
#define ctn(a) a - 65
#define mp make_pair
#define pb push_back
#define sz size()
#define p32 pair<int,int>
#define p64 pair<ll,int>
#define pdd pair<double,double>
#define fi first
#define se second
#define tse se.fi
#define th se.se
#define tri pair<int,p32>
#define repn(i,e) for(int i = 0; i < e; i++)
#define repsn(i,s,e) for(int i = s; i < e; i++)
#define v64 vector<ll>
#define v32 vector<int>
#define vp64 vector<p64>
#define vp32 vector<p32>
#define vprint(a,sz) repn(k,sz) cout << setw(3) << right << a[k] << " "; cout << endl
#define mprint(a,rn,cn) repn(i,rn) { vprint(a[i],cn); cout << endl; }
#define INF32 INT_MAX
#define INF64 LLONG_MAX
#define pq priority_queue

int N, a, b;
string s;

void pp32(p32 p) { cout << "( " << p.fi << ", " << p.se << " )" << endl; }
void pp64(p64 p) { cout << "( " << p.fi << ", " << p.se << " )" << endl; }
void ptri(tri t) { cout << "( " << t.fi << ", " << t.tse << ", " << t.th << " )" << endl; }
inline void fastio() { ios_base::sync_with_stdio(false); cin.tie(0); }
int dist(int x,int y) { return (s[x]==s[y]) ? 0 : abs(y-x); }

int main(void) {
	fastio();
	cin >> N >> a >> b >> s;
	cout << abs(s[a-1] - s[b-1]) << endl;
}
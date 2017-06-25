#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define mp make_pair
#define fi first
#define se second

using namespace std;

int a,b,n;
vector<pair<int,int>> v;
int d;
pair<int,pair<int,int>> hi;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
  	cin >> a >> b;
    v.push_back(mp(a,b));
    if(b-a+1 > d) {
    	hi = mp(i+1,mp(a,b));
    }
    d = max(d,b-a+1);
  }
  for(int i = 0; i < n; i++) {
  	if(hi.se.fi > v[i].fi || hi.se.se < v[i].se) {
    	cout << -1 << endl;
        return 0;    	
    }
  }
  cout << hi.fi << endl;
  return 0;
}
#include<iostream>
#include<queue>
#include<utility>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long
#define ii pair<ll,ll>
#define iii pair<pair<ll,ll>,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n,p;
ll a,b,c,eA,eB,eC,t,h;
priority_queue<iii> C;
priority_queue<iii,vector<iii>,greater<iii> > A;
priority_queue<ii,vector<ii>,greater<ii> > ans;
vector<iii> v;
queue<iii> B;
iii cur;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> c;

	for(int i = 0; i < n; i++) {
		cin >> t >> h;
		v.pb(mp(mp(t,h),i));
	}
	sort(v.begin(),v.end());

	for(int i = 0; i < n; i++) {
		t = v[i].fi.fi, h = v[i].fi.se, p = v[i].se;
		while(eA <= t && A.size()) {
			cur = A.top();
			eA = max(eA,cur.fi.se);
			eA = eA + a;
			A.pop();
			ans.push(mp(cur.se,eA));
		}
		while(eB <= t && B.size()) {
			cur = B.front();
			eB = max(eB,cur.fi.se);
			eB = eB + b;
			B.pop();
			ans.push(mp(cur.se,eB));
		}
		while(eC <= t && C.size()) {
			cur = C.top();
			eC = max(eC,cur.fi.se);
			eC = eC + c;
			C.pop();
			ans.push(mp(cur.se,eC));
		}
		if(!A.size() && t >= eA) A.push(mp(mp(h,t),p));
		else if(!B.size() && t >= eB) B.push(mp(mp(h,t),p));
		else if(!C.size() && t >= eC) C.push(mp(mp(h,t),p));
		else {
			if(A.size() <= B.size() && A.size() <= C.size()) {
				A.push(mp(mp(h,t),p));
			} else if(B.size() <= C.size() && B.size() <= A.size()) {
				B.push(mp(mp(h,t),p));
			} else {
				C.push(mp(mp(h,t),p));
			}
		}
	}
	while(A.size()) {
		cur = A.top();
		eA = max(eA,cur.fi.se);
		eA = eA + a;
		A.pop();
		ans.push(mp(cur.se,eA));
	}
	while(B.size()) {
		cur = B.front();
		eB = max(eB,cur.fi.se);
		eB = eB + b;
		B.pop();
		ans.push(mp(cur.se,eB));
	}
	while(C.size()) {
		cur = C.top();
		eC = max(eC,cur.fi.se);
		eC = eC + c;
		C.pop();
		ans.push(mp(cur.se,eC));
	}

	while(ans.size()) {
		cout << ans.top().se << "\n";
		ans.pop();
	}
	return 0;
}
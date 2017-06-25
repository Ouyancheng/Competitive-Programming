#include<bits/stdc++.h>

using namespace std;

typedef struct car {
	long long price;
	long long fuel;
} car;

vector<car> cars;
vector<long long> stn;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	long long s,t,a,b,MN=1e9+1,MX=-1, ans = 1e9+1;
	cin >> n >> k >> s >> t;
	for(int i = 0; i < n; i++) {
		car tc;
		cin >> a >> b;
		tc.price = a,tc.fuel = b;
		cars.push_back(tc);
		MN = min(MN,b);
		MX = max(MX,b);
	}
	for(int i = 0; i < k; i++) {
		cin >> a;
		if(a >= s) {
			k = i + 1;
			break;
		}
		stn.push_back(a);
	}
	k++;
	stn.push_back(s);
	sort(stn.begin(),stn.end());
	long long lo = 0, hi = 1e9, fuel = 0;
	while(lo <= hi) {
		long long mid = (lo + hi)/2;
		long long ttime = 0,dsofar = 0;
		for(int i = 0; i < k; i++) {
			if(mid < stn[i]-dsofar) { ttime = INT_MAX; break; }
			ttime += ((2 * (stn[i]-dsofar)) - min(stn[i]-dsofar,mid-(stn[i]-dsofar)));
			if(ttime > t) break;
			dsofar = stn[i];
		}
		if(ttime <= t) {
			fuel = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	if(fuel > 0 && fuel <= MX) {
		for(int i = 0; i < cars.size(); i++) {
			if(cars[i].fuel >= fuel) {
				ans = min(ans,cars[i].price);
			}
		}
		cout << ans << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
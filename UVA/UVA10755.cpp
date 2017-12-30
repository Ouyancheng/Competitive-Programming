#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

#define vi vector<ll>
#define vvi vector< vector<ll> >
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,s,n) for(int i = s; i < n; i++)
#define pb push_back

int n, m, h, t;
ll val;
vector< vvi > cuboid;

// helper function to get optimal value of a cuboid
ll calculate(int ri,int rj,int hi,int hj) {
	ll val = 0, tmax = 0, gmax = -(1LL << 60);
	rep(ci,m) { // apply kadane's max sum subarray algorithm
		val = 0;
		// start from hi and end at hj inclusive
		reps(hii,hi,hj+1) { // use prefix sum to sum from top to bottom row
			val += cuboid[hii][rj][ci]-cuboid[hii][ri-1][ci];
		}
		// Procedure for Kadane's algorithm
		tmax = max(tmax+val,val);
		gmax = max(gmax,tmax);
	}
	return gmax;
}

ll solve() {
	ll gmax = -(1LL << 60);
	rep(hi,h) { // fix the top layer
		reps(hj,hi,h) { // fix the bottom layer
			reps(ri,1,n+1) { // fix the top row
				reps(rj,ri,n+1) { // fix the bottom row
					// Get optimal value for this cuboid
					gmax = max(gmax,calculate(ri,rj,hi,hj));
				}
			}
		}
	}
	return gmax;
}

int main(void) {
	// fast i/o
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	
	// process one cuboid at a time
	while(t--) {
		cin >> n >> m >> h;
		cuboid.assign(h,vvi()); // Create n layers for the cuboid

		rep(i,h) {
			cuboid[i].pb(vi()); // Create a additional row for vertical prefix sum
			cuboid[i][0].assign(m,0);
		}
		rep(k,n) { // for each row
			rep(i,h) { // for each layer
				cuboid[i].pb(vi()); // create one row
			}
			rep(j,m) { // For each column
				rep(i,h) { // For each layer
					cin >> val;
					cuboid[i][k+1].pb(val); // 1 offset because of initial row
				}
			}
		}
		// calculate prefix sum for each layer
		rep(i,h) { // For each layer
			rep(j,n) { // For each row
				rep(k,m) { // Calculate prefix sum
					cuboid[i][j+1][k] += cuboid[i][j][k];
				}
			}
		}
		cout << solve() << "\n";
		if(t) {
			cout << "\n";
		}
	}
	return 0;
}
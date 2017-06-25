#include<iostream>
#include<algorithm>

#define mod 10007

using namespace std;

long long s[100000],w[100000],n,a;
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		  cin >> a;
		  s[i]=a;
		  w[i]=a;
	}
	sort(s,s+n);
	sort(w,w+n);
	reverse(w,w+n);
	for(int i = 0; i < n; i++) {
		   ans = (ans+w[i]*s[i])%mod;
		}
		cout << ans << "\n";
		return 0;
}
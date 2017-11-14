#include<iostream>

using namespace std;

typedef long long ll;

ll a,b;

ll gcd(ll a,ll b) {
  return (b == 0) ? a : gcd(b,a%b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	ll c = gcd(a,b);
	cout << a/c << "/" << b/c << "\n";
	return 0;
}
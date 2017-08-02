#include<iostream>
 
using namespace std;
 
int n,p,ans;
 
int main() {
	cin >> n;
	while((1 << p) <= n) {
		ans = (1 << p);
		p++;
	}
	cout << ans << "\n";
}
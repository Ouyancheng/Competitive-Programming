#include<iostream>

using namespace std;

#define MOD 1000000007

int x,y,n;
int mem[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y >> n;
	n--;
	mem[0] = x, mem[1] = y, mem[2] = y - x, mem[3] = -x, mem[4] = -y, mem[5] = x-y;
	cout << (0LL + mem[n%6] + MOD + MOD) % MOD;
	cout << "\n";
	return 0;
}
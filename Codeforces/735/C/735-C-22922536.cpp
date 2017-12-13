#include<iostream>
using namespace std;

#define ll long long

ll f[4], N, i, ans;

int main(void)
{
	cin >> N;
	f[1] = 0, f[2] = 1;
	while(++i) {
		f[3] = f[2] + f[1];
		if(f[3] <= N) ans = i;
		else break;
		f[1] = f[2];
		f[2] = f[3];
	}
	cout << ans-1 <<endl;
	return 0;
}
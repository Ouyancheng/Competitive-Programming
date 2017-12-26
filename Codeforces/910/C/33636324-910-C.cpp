#include<iostream>
#include<string>
#include<cassert>

using namespace std;

string s;
const int maxn = 1e6 + 5;
int n, a, b, l;
int remA[maxn], remB[maxn], num[maxn];

void print(int a, int b, int arr[]) {
	for(int i = a; i <= b; i++) {
		cout << arr[i];
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> a >> b;
	n = (int) s.length();
	for(int i = 0; i < n; i++) {
		num[i+1] = (int) (s[i] - '0');
	}
	for(int i = 1; i <= n; i++) {
		remA[i] = (remA[i-1]  * 10 + num[i]) % a;
	}
	for(int i = n, d = 1; i > 0; i--, d = (d * 10) % b) {
		remB[i] = (num[i] * d + remB[i+1]) % b;
	}
	for(int i = 1; i <= n-1; i++) {
		if(remA[i] == 0 && remB[i+1] == 0 && num[i+1] != 0) {
			cout << "YES" << "\n";
			print(1,i,num);
			print(i+1,n,num);
			return 0;
		}
	}

	cout << "NO" << "\n";
	return 0;
}

#include<iostream>

using namespace std;

#define MAX_N 100005

int n,k;
int o[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < k; i++) o[i] = n-i;
	for(int i = k; i < n; i++) o[i] = i-k+1;
	for(int i = 0; i < n; i++) cout << o[i] << " ";
	cout << "\n";
	return 0;
}
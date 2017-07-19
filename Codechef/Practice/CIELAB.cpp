#include<iostream>

using namespace std;

int a,b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	int diff = a - b;
	int f = (diff + 1) % 9 + 1;
	diff = (diff/10) * 10 + f;
	cout << diff << "\n";
	return 0;
}

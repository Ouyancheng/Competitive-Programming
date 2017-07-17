#include<iostream>

using namespace std;

int n;
int t1,t2,a,b;

int main() {
	while(cin >> n && n) {
		t1 = t2 = n;
		a = b = 0;
		while(t1) {
			a |= (t1 & -t1);
			t1 -= (t1 & -t1);
			t1 -= (t1 & -t1);
		}
		t2 -= (t2 & -t2);
		while(t2) {
			b |= (t2 & -t2);
			t2 -= (t2 & -t2);
			t2 -= (t2 & -t2);
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}
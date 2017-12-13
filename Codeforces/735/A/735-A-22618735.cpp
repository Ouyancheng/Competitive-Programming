#include<iostream>

using namespace std;
/*
5 2
#G#T#
*/
int main(void) {
	int a,b,p;
	char c;
	cin >> a >> b;
	char k[a];

	if(b == 0) {
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 0; i < a; ++i) {
		cin >> k[i];
		if(k[i]=='G') p = i;
	}
	for(int i = p; i >= 0; i -= b) {
		if(k[i] == 'T') {
			cout << "YES" << endl;
			return 0;
		} else if(k[i] == '#') {
			break;
		}
	}
	for(int i = p; i < a; i += b) {
		if(k[i] == 'T') {
			cout << "YES" << endl;
			return 0;
		} else if(k[i] == '#') {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
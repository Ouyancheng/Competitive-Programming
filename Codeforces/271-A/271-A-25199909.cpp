#include<iostream>

using namespace std;

bool can(int n) {
	int used = 0;
	while(n) {
		if(used & (1<<(n % 10))) {
			return false;
		}
		used |= (1<<(n%10));
		n /= 10;
	}
	return true;
}

int y;

int main(void) {
	cin >> y;
	++y;
	while(!can(y)) {
		y++;
	}
	cout << y << endl;
}
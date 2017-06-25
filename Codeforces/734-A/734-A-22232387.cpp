#include<iostream>

using namespace std;

int main(void) {
	string s;
	int i;

	cin >> i >> s;
	int x = 0, y = 0;

	for(int a = 0; a < i; a++) {
		if(s[a] == 'A') {
			x++;
		} else {
			y++;
		}  
	}
	if(x > y) cout << "Anton";
	else if(x < y) cout << "Danik";
	else cout << "Friendship";
	cout << endl;
}
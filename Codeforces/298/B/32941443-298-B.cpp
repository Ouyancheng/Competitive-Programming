#include<iostream>
#include<string>

using namespace std;

int t, si, sj, ei, ej;
int north, south, east, west;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t >> sj >> si >> ej >> ei >> s;

	for(int i = 0; i < t; i++) {
		if(s[i] == 'N') {
			if(si < ei) {
				si++;
			}
		} else if(s[i] == 'S') {
			if(si > ei) {
				si--;
			}
		} else if(s[i] == 'E') {
			if(sj < ej) {
				sj++;
			}
		} else {
			if(sj > ej) {
				sj--;
			}
		}
		if(si == ei && sj == ej) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}
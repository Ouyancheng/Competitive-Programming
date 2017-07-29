#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int t,m,f;
string s;

int main() {
	cin >> t;
	getline(cin,s);
	while(t--) {
		getline(cin,s);
		m = count(s.begin(),s.end(),'M');
		f = count(s.begin(), s.end(),'F');
		if(m + f <= 2 || m != f) {
			cout << "NO LOOP";
		} else {
			cout << "LOOP";
		}
		cout << "\n";
	}
	return 0;
}
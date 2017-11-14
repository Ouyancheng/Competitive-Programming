#include<iostream>
#include<string>
#include<vector>

using namespace std;

string s;
vector<char> big, small;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	for(int i = 0; i < (int) s.length(); i++) {
		if(s[i] >= 'a' && s[i] <= 'z') {
			small.push_back(s[i]);
		} else if(s[i] >= 'A' && s[i] <= 'Z') {
			big.push_back(s[i]);
		}
	}
	for(int i = 0; i < (int) big.size(); i++) {
		cout << big[i];
	}
	for(int i = 0; i < (int) small.size(); i++) {
		cout << small[i];
	}
	cout << "\n";
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> a;
string s;
int ans = 0;

int main(void) {
	cin >> s;
	a.push_back(-1);
	for(int i = 0; i < s.length(); i++) {
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y') {
			a.push_back(i);
		}
	}
	a.push_back(s.length());
	for(int i = 1; i < a.size(); i++) {
		ans = max(ans,a[i]-a[i-1]);
	}
	cout << ans << endl;
	return 0;
}
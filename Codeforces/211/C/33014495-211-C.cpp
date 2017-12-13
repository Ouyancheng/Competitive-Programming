#include<iostream>
#include<string>

using namespace std;

string s, ans;
int ai;

int main() {
	cin >> s;
	for(char c : s) {
		if((int) ans.length() >= 2 && ans[ai-1] == c && ans[ai-2] == c) {
			continue;
		} else if((int) ans.length() >= 3 && ans[ai-1] == c && ans[ai-2] == ans[ai-3]) {
			continue;
		} else {
			ans += c;
			ai++;
		}
	}
	cout << ans << "\n";
}

#include<bits/stdc++.h>

using namespace std;

string s;

void go(int o) {
	for(int i = 0; i < 2 * o; i++) {
		cout << " ";
	}
}

void work(char p = '#', int cur = 0, int open = 0) {
	if(cur == (int) s.length()) {
		return;
	}
	if(s[cur] == '{') {
		if(cur != 0) {
			cout << "\n";
		}
		go(open);
		cout << s[cur];
		work(s[cur], cur + 1, open + 1);
	} else if(s[cur] == '}') {
		cout << "\n";
		go(open-1);
		cout << s[cur];
		work(s[cur], cur + 1, open - 1);
	} else if(s[cur] == ',') {
		cout << s[cur];
		work(s[cur], cur+1, open);
	} else {
		if(p == '{' || p == '}' || p == ',') {
			cout << "\n";
			go(open);
		}
		cout << s[cur];
		work(s[cur], cur + 1, open);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	work();
	cout << "\n";
	return 0;
}
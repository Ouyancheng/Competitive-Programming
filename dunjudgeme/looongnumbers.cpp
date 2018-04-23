#include<bits/stdc++.h>

using namespace std;

string s1, s2, s3;

void sum(int i1 = 0, int i2 = 0, int c = 0) {
	if(i1 >= s1.length() && i2 >= s2.length()) {
		if(c == 1) {
			s3 += string() + '1';
		}
		return;
	}
	int d1 = (i1 >= s1.length() ? 0 : s1[i1] - '0');
	int d2 = (i2 >= s2.length() ? 0 : s2[i2] - '0');
	if(d1 + d2 + c < 10) {
		s3 += string() + ((char) ((d1 + d2 + c) + '0'));
		c = 0;
	} else {
		s3 += string() + ((char) ((d1 + d2 + c - 10) + '0'));
		c = 1;
	}
	sum(i1 + 1, i2 + 1, c);
}

int main() {
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	sum();
	reverse(s3.begin(), s3.end());
	cout << s3 << endl;
	return 0;
}
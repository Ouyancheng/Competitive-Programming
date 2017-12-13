#include<iostream>
#include<string>

using namespace std;

string s;
int a, b, q;
int pf[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> q;
	s += "$";
	for(int i = 0; i < (int) s.length(); i++) {
		pf[i+1] = (s[i] == s[i+1]);
		pf[i+1] += pf[i];
	}
	for(int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << pf[b-1] - pf[a-1] << "\n";
	}
	return 0;
}

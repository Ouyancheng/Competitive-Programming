#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

int n, a[10],c;
string str;
istringstream ss;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ws;
		c = 0;
		getline(cin,str);
		ss.clear();
		ss.str(str);
		while(ss >> a[c]) c++;
		sort(a,a+c);
		cout << "Case " << i + 1 << ": " << a[c/2] << "\n";
	}
	return 0;
}
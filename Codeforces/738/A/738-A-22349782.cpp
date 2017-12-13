#include<bits/stdc++.h>

using namespace std;

int main(void) {
	int n = 0;
	vector<string> filler;
	string s = "", txt = "";
	cin >> n >> txt;

	filler.push_back("ogo");
	s = "ogogo";
	while(s.length() <= n) {
		filler.push_back(s);
		s += "go";
	}
	for(int i = filler.size()-1; i >= 0; i--) {
		while(txt.find(filler[i]) != string::npos)
			txt = txt.replace(txt.find(filler[i]),filler[i].length(),"***");
	}
	cout << txt << endl;
	return 0;
}
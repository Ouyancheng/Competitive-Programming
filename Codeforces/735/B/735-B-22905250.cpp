#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int t,f,s,w[100005],fc,sc;
double wff,wss;

int main(void) {
	cin >> t >> f >> s;
	for(int i = 0 ; i < t; i++) {
		cin >> w[i];
	}
	sort(w,w+t,greater<int>());
	cout.precision(8);
	if(f < s) {
		for(int i = 0; i < t; i++) {
			if(fc < f) wff+=w[i],fc++;
			else if(sc < s) wss+=w[i],sc++;
			else break;
		}
		cout << fixed;
		cout <<  wff/fc + ((sc==0) ? 0 : wss/sc)<< endl;
	} else {
		for(int i = 0; i < t; i++) {
			if(sc < s) wss+=w[i],sc++;
			else if(fc < f) wff+=w[i],fc++;
			else break;
		}
		cout << fixed;
		cout <<  wss/sc + ((fc==0) ? 0 : wff/fc)<< endl;
	}
	return 0;
}
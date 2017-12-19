#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cc,as,n[35];
string n1,n2;
long long d1,d2;

int main() {
	//code
	cin >> cc;
	for(int i = 0; i < cc; i++) {
	    cin >> as;
	    n1 = "", n2 = "";
	    for(int j = 0; j < as; j++) {
	        cin >> n[j];
	    }
	    if(as&1) {
	        n[as++] = 0;
	    }
	    sort(n,n+as);
	    for(int j = 0; j < as-1; j+=2) {
	        if(n[j]) n1 += to_string(n[j]);
	        if(n[j+1]) n2 += to_string(n[j+1]);
	    }
	    d1 = (n1.length()==0) ? 0 : stoll(n1);
	    d2 = (n2.length()==0) ? 0 : stoll(n2);
	    cout << d1 + d2 << endl;
	}
	return 0;
}
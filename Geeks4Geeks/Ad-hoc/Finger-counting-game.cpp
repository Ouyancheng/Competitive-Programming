#include <iostream>

using namespace std;

int t,a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	int one[] = { 1,2,3,4,5,4,3,2,1 };
	int ten1[] = { 2,3,4,5,4,3,2,1,2,3 };
	int ten2[] = { 4,5,4,3,2,1,2,3,4,5 };
    int ten3[] = { 4,3,2,1,2,3,4,5,4,3 };
	int ten4[] = { 2,1,2,3,4,5,4,3,2,1 };
	while(t--) {
	    cin >> a;
	    if(a < 10) {
	        cout << one[a-1];
	    } else {
	        int k = a/10 - 1;
	        k %= 4;
	        if(k == 0) {
	            cout << ten1[a%10];
	        } else if(k == 1) {
	            cout << ten2[a%10];
	        } else if(k == 2) {
	            cout << ten3[a%10];
	        } else if(k == 3) {
	            cout << ten4[a%10];
	        }
	    }
	    cout << "\n";
	}
	return 0;
}
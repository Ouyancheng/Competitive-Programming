#include <iostream>
using namespace std;

int num[100];
int cc;
int n,l,r;

int main() {
	//code
	cin >> cc;
	for(int i = 0; i < cc; i++) {
	    cin >> n;
	    for(int j = 0; j < n; j++) {
	        cin >> num[j];
	    }
	    for(int j = n-1; j >= 0; j--) {
	        int k = j;
	        while(k < n-1 && num[k] < 0 && num[k+1] >= 0) {
	            swap(num[k],num[k+1]);
	            k++;
	        }
	    }
	    if(num[n-1] < 0 && num[0] >= 0) {
    	    cout << num[0];
    	    for(int j = 1; j < n; j++) {
    	        cout << " " << num[j];
    	    }
	    }
	    cout << endl;
	}
	
	return 0;
}
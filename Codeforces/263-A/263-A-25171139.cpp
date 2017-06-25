#include<iostream>
#include<cmath>

using namespace std;

int r,c,d;

int main(void) {
    for(int i = 1; i <= 5; i++) {
    	for(int j = 1; j <= 5; j++) {
        	cin >> d;
            if(d) r = i, c = j;
        }
    }
   cout << abs(r-3) + abs(c-3) << endl;
	return 0;
}
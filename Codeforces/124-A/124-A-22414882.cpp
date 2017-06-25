#include <iostream>

using namespace std;

int main(void){
	int a,b,c;
	ios_base::sync_with_stdio(false);
	cin.tie (0);
	cout.tie (0);
	cin>> a >>b>>c;
	int pos;
	for(pos= b +1;pos<a-c;pos++);
	cout << (pos<=a?a-pos+1: 0)<< endl;
}
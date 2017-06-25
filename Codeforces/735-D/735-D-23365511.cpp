#include<iostream>
#include<cstdlib>

using namespace std;

int n;

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n <= 3) return true;

	if (n%2 == 0 || n%3 == 0) return false;

	for (int i=5; i*i<=n; i=i+6)
		if (n%i == 0 || n%(i+2) == 0)
		return false;

	return true;
}

int main(void) {
	cin >> n;
	if(isPrime(n)) {
		cout << "1";
	} else if(n&1 && !isPrime(n-2)) {
		cout << "3";
	} else {
		cout << "2";
	}
	cout << endl;
	return 0;
}
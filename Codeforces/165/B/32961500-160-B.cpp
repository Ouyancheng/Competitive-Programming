#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
string s;
int A[105], B[105];
bool smaller = true;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		A[i] = s[i] - '0';
	}
	for(int i = n; i < (int) s.length(); i++) {
		B[i-n] = s[i] - '0';
	}
	sort(A,A+n);
	sort(B,B+n);
	for(int i = 0; i < n; i++) {
		if(A[i] > B[i]) {
			smaller = false;
			break;
		} else if(A[i] == B[i]) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	if(!smaller) {
		for(int i = 0; i < n; i++) {
			if(A[i] < B[i]) {
				cout << "NO" << "\n";
				return 0;
			} else if(A[i] == B[i]) {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
    return 0;
}

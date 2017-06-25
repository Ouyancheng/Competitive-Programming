#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a,b;
int ans,pas;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a >> b;
        pas = pas - a + b;
        ans = max(ans,pas);
    }
    cout << ans << endl;
	return 0;
}
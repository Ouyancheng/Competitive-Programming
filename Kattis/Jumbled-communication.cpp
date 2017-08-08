#include<iostream>

using namespace std;

int ans,n,t;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> t;
        ans = 0;
        ans ^= (t&1);
        for(int i = 1 ; i < 8; i++) {
            if((ans & (1 << (i-1))) != 0) {
                if((t & (1 << i)) == 0) {
                    ans ^= (1 << i);
                }
            } else {
                if((t & (1 << i)) != 0) {
                    ans ^= (1 << i);
                }
            }
        }
        cout << ans << " ";
    }
    return 0;
}
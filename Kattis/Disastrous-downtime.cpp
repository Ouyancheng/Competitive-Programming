#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int n,k,a,ans;
queue<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a;
        while((int) s.size() > 0 && a-s.front() >= 1e3) {
            s.pop();
        }
        s.emplace(a);
        ans = max(ans,(int) s.size());
    }
    cout << (int) ceil(1.0*ans/k);
    return 0;
}
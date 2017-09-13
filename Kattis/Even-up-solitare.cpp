#include <bits/stdc++.h>
using namespace std;

int n, x;
vector <int> a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(n-- && cin >> x)
        a.push_back(x%2);
    for(int i = 0 ; i < a.size() ; i++){
        if(b.size() == 0) b.push_back(a[i]);
        else if(b.back()+a[i]&1) b.push_back(a[i]);
        else b.pop_back();
    }
    cout << b.size() << endl;
    return 0;
}

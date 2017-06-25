#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define vii vector<ii>

vii v;

int n,q;
int arr[100005];
string win;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    for(int i = 0; i < q; i++) {
        v.clear();
        win = "ANDY";
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
            if(v.size()) {
                v.pb(max(v.back(),mp(arr[j],j)));
            } else {
                v.pb(mp(arr[j],j));
            }
        }       
        while(v.size()) {
            win = (win == "ANDY" ? "BOB" : "ANDY");
            ii p = v.back();
            while(v.size() && arr[(v.size()-1)] != v.back().fi) {
                v.pop_back();
            }
            v.pop_back();
        }
        cout << win << "\n";
    }
    return 0;
}

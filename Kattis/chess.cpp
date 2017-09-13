#include<iostream>
#include<cmath>
#include<utility>
#include<cstring>

using namespace std;

int n,a1,a2;
char c1,c2;
pair<char,int> arr[50];

bool can(char cc, int c) {
    return cc >= 'A' && cc <= 'H' && c > 0 && c < 9;
}

int gen(char c,int n) {
    char a = c; int b = n, i = 0;
    while(can(--a,--b)) {
        arr[i++] = make_pair(a,b);
    }
    a = c, b = n;
    while(can(--a,++b)) {
        arr[i++] = make_pair(a,b);
    }
    a = c, b = n;
    while(can(++a,--b)) {
        arr[i++] = make_pair(a,b);
    }
    a = c, b = n;
    while(can(++a,++b)) {
        arr[i++] = make_pair(a,b);
    }
    /*
    for(int j = 0; j < i; j++) {
        cout << "( " << arr[j].first <<  ", " << arr[j].second << ")" << "\n";
    }
    cout << "\n";
    */
    return i;
}

bool meet(char c1,int a1,char c2,int a2) {
    return (int) abs(c2 - c1) == (int) abs(a1 - a2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--) {
        memset(arr,0,sizeof arr);
        cin >> c1 >> a1 >> c2 >> a2;
        if(c1 == c2 && a1 == a2) {
            cout << 0 << " " << c1 << " " << a1;
        } else if(meet(c1,a1,c2,a2)) {
            cout << 1 << " " << c1 << " " << a1 << " " << c2 << " " << a2;
        } else {
            int sz = gen(c2,a2);
            int flag = -1;
            for(int i = 0; i < sz; i++) {
                if(meet(c1,a1,arr[i].first,arr[i].second)) {
                    flag = i;
                    break;
                }
            }
            if(flag < 0) {
                cout << "Impossible";
            } else {
                cout << 2 << " " << c1 << " " << a1 << " " << arr[flag].first << " " << arr[flag].second << " " << c2 << " " << a2;
            }
        }
        cout << "\n";

    }
    return 0;
}
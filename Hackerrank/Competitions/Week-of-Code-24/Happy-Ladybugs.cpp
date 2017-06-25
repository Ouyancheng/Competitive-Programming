#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int Q;
    cin >> Q;
    
    for(int a0 = 0; a0 < Q; a0++){
        //cout << "a0 " << a0 << " " << Q << endl;
        int n;
        cin >> n;
        string b;
        cin >> b;
        int nc = 0;
        int u[26] = { 0 },v[26] = { 0 };
        for(int i = 0; i < b.length(); i++) {
            if(b[i] >= 'A' && b[i] <= 'Z') u[b[i]-'A']++;
            else nc++;
        }
        int o = n-1;
        int i,j,f = 0;
        // some character only appear once
        for(i = 0; i < n; i++) {
            if(u[b[i]-'A']==1) {
                cout << "NO" << endl;
                f = 1;
                break;
            }
        }
        if(f) continue;
        f = 1;
        // all characters are the same
        if(u[b[0]-'A']==n) {
            cout << "YES" << endl;
            f = 0;
        }
        if(!f) continue;

        f = 0;
        // elements are all next to each other already
        for(int i = 0; i < n; i++) {
            //cout << i << " ";
            if(v[b[i]-'A']) {
                f = 1;
                break;
            }
            v[b[i]-'A'] = 1;
            while(i < n-1 && b[i]==b[i+1]) i++;
        }
        //cout << endl;
        //cout << "HERE" << " " << nc << endl;
        if(!f) {
            cout << "YES" << endl;
            continue;
        }
        else {
            if(nc) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}



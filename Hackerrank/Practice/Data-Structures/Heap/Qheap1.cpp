#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int cc = 0;
    priority_queue<long,vector<long>,greater<long>> pq;
    unordered_map<long,int> val;
    cin >> cc;
    long a,b;
    while(cc-- >= 1) {
        cin >> a;
        switch(a) {
            case 1:
                cin >> b;
                pq.push(b);
                if(val.find(b)==val.end()) val.insert(pair<long,int>(b,1));
                else val[b] = 1;
                break;
            case 2:
                cin >> b;
                val[b] = 0;
                break;
            case 3:
                while(!val[pq.top()]) {
                    pq.pop();
                }
                cout << pq.top() << endl;
            break;
        }
    }
    return 0;
}
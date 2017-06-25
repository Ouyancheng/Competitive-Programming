#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    cout.precision(1);
    cout << fixed;
    priority_queue<int,vector<int>,greater<int>> minh;
    priority_queue<int> maxh;
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
       if(maxh.size()==0 || maxh.top() > a[a_i]) {
           maxh.push(a[a_i]);
       } else {
           minh.push(a[a_i]);
       }
       if(maxh.size() > minh.size()+1) {
           minh.push(maxh.top());
           maxh.pop();
       }
       if(minh.size() > maxh.size()+1) {
           maxh.push(minh.top());
           minh.pop();
       }
       if(minh.size()==maxh.size()) {
           cout << (minh.top()+maxh.top())/2.0 << endl;
       } else {
           cout << ((minh.size() > maxh.size()) ? minh.top() : maxh.top())/1.0 << endl;
       }
    }
    return 0;
}

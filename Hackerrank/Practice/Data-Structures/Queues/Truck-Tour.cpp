#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int circ(vector<int> &gas, vector<int> &cost) {
    int min_S=INT_MAX, S=0, position=0;
    for(int i=0;i<gas.size();i++)
    {
        S += gas[i] - cost[i];
        if(S<min_S)
        {
            min_S = S;
            position = (i+1) % gas.size();
        }
    }
    if(S>=0)
        return position;
    else
        return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int sc = 0;
    cin >> sc;
    int f[sc], d[sc];
    vector<int> fa;
    vector<int> da;
    for(int i = 0; i < sc; i++) {
        cin >> f[i];
        cin >> d[i];
        fa.push_back(f[i]);
        da.push_back(d[i]);
    }
    cout << circ(fa,da);
}

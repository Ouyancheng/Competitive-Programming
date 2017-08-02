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

int number_needed(string a, string b) {
   int Acount[26], Bcount[26];
    fill_n(Acount,26,0);
    fill_n(Bcount,26,0);
    for(int i = 0; i < a.length(); i++) {
        Acount[a[i]-97]++;
    }
    for(int i = 0; i < b.length(); i++) {
        Bcount[b[i]-97]++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        ans += abs(Acount[i]-Bcount[i]);
    }
    return ans;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}

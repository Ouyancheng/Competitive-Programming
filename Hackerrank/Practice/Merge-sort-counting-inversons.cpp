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

long long inv(int i,int l1,int j,int l2,int buf[],vector<int> &s) {
	int k = 0;
    long long ans = 0;
	while(i <= l1 && j <= l2) {
		if(s[i] <= s[j]) buf[k++] = s[i++];
		else buf[k++] = s[j++],ans+=l1-i+1;
	}
	while(i <= l1) buf[k++] = s[i++];
	while(j <= l2) buf[k++] = s[j++];
	return ans;
}

long long ci(int lo,int hi,vector<int> &s) {
	if(lo == hi) return 0;
	long long ans = 0;
    int buf[(hi-lo+1)<<1];
	ans += ci(lo,(lo+hi)>>1,s);
	ans += ci(((lo+hi)>>1)+1,hi,s);
	ans += inv(lo,(lo+hi)>>1,((lo+hi)>>1)+1,hi,buf,s);
	for(int i = 0; i < hi-lo+1; i++) s[lo+i] = buf[i];
	return ans;
}

long long count_inversions(vector<int> a) {
  return ci(0,a.size()-1,a);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}

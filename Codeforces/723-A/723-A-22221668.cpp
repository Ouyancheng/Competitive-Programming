#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int a,b,c;
	cin >> a >> b >> c;
	int hi = max(a,max(b,c));
	
	int d[hi+1];
    memset(d,1<<30,hi+1);
    int ans = 1 << 30;
    
    d[a] = 0;
    
	for(int i = a + 1, val = 0; i < hi+1; i++, val++) d[i] = val + 1; 
	for(int i = a - 1, val = 0; i >= 0; i--, val++) d[i] = val + 1;

	for(int i = b + 1, val = 0; i < hi+1; i++, val++) d[i] += val + 1; 
	for(int i = b - 1, val = 0; i >= 0; i--, val++) d[i] += val + 1;
	
	for(int i = c + 1, val = 0; i < hi+1; i++, val++) d[i] += val + 1; 
	for(int i = c - 1, val = 0; i >= 0; i--, val++) d[i] += val + 1;
	for(int i = 0; i < hi + 1; i++) ans = min(ans,d[i]);
	
	cout << ans << endl;
	return 0;
}
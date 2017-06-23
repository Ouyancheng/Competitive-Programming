#include<iostream>

using namespace std;

long long s[50001];
int cc, n;

bool cmp(pair<int,string> p1,pair<int,string> p2) {
	return p1.first < p2.first;
}

int inv(int i,int l1,int j,int l2,int buf[]) {
	int k = 0, ans = 0;
	while(i <= l1 && j <= l2) {
		if(s[i] <= s[j]) buf[k++] = s[i++];
		else buf[k++] = s[j++],ans+=l1-i+1;
	}
	while(i <= l1) buf[k++] = s[i++];
	while(j <= l2) buf[k++] = s[j++];
	return ans;
}

int ci(int lo,int hi) {
	if(lo == hi) return 0;
	int ans = 0, buf[(hi-lo+1)<<1];
	ans += ci(lo,(lo+hi)>>1);
	ans += ci(((lo+hi)>>1)+1,hi);
	ans += inv(lo,(lo+hi)>>1,((lo+hi)>>1)+1,hi,buf);
	for(int i = 0; i < hi-lo+1; i++) s[lo+i] = buf[i];
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> cc;
	for(int c = 0; c < cc; c++) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> s[i];
		}
		cout << ci(0,n-1) << endl;
	}
	return 0;
}
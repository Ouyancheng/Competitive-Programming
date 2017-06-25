#include<bits/stdc++.h>

using namespace std;

int arr[1000][1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,ans=0;
	cin >> n >> m;
	memset(arr,0,m*n*sizeof(int));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int s = 0;

	for(int i = 0; i < n; i++) {
		s = 0;
		for(int j = 0; j < m; j++) {
			if(arr[i][j]) s = 1;
			else ans += s;
		}
		s = 0;
		for(int j = m-1; j >= 0; j--) {
			if(arr[i][j]) s = 1;
			else ans += s;
		}
	}
	for(int i = 0; i < m; i++) {
		s = 0;
		for(int j = 0; j < n; j++) {
			if(arr[j][i]) s = 1;
			else ans += s;
		}
		s = 0;
		for(int j = n-1; j >= 0; j--) {
			if(arr[j][i]) s = 1;
			else ans += s;
		}
	}
	cout << ans << endl;

	return 0;
}
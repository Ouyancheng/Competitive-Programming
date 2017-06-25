#include<bits/stdc++.h>

using namespace std;

int n;
int a[100];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    a[i] = i+1;
  }
  for(int i = 0; i < n - 1; i+=2) {
    swap(a[i],a[i+1]);
  }
  for(int i = 0; i < n; i++) {
    if(a[i] == i + 1 || a[a[i]-1] != i+1) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(int i = 0; i < n; i++) {
    if(a[i] != 0) cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
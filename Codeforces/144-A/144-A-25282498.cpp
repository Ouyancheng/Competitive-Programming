#include<iostream>
#include<algorithm>

using namespace std;

int n;
int f,b = 101;
int fi,bi;
int t;
int a[100];

int main(void) {
  cin >> n;
  for(int i = 0; i < n; i++) {
  	cin >> a[i];
    if(a[i] > f) f = a[i], fi = i;
  }
  for(int i = fi; i >= 1; i--) {
    swap(a[i],a[i-1]);
  }
  for(int i = n-1; i >= 0; i--) {
    if(a[i] < b) b = a[i], bi = n-i-1;
  }
  cout << fi + bi << endl;
  return 0;
}
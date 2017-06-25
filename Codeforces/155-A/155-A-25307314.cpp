#include<iostream>

using namespace std;

int n;
int a,ans;
int maxsf,minsf;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> minsf;
  maxsf = minsf;
  for(int i = 0; i < n-1; i++) {
  	cin >> a;
    if(a < minsf) {
      ans++;
      minsf = a;
    } else if(a > maxsf) {
      ans++;
      maxsf = a;
    }
  }
  cout << ans << endl;
  return 0;
}
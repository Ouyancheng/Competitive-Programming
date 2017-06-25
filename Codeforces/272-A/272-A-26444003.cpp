#include<iostream>

using namespace std;

int n,f,a,ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    f += a;
  }
  for(int i = 1; i <= 5; i++) {
    if((i+f) % (n+1) != 1) ans++;
  }
  cout << ans << endl;
}
#include<iostream>

using namespace std;

int n,a,sum,b[8];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= 7; i++) {
    cin >> b[i];
  }
  while(true) {
    for(int i = 1; i <= 7; i++) {
      if((sum += b[i]) >= n) {
        cout << i << endl;
        return 0;
      }
    }
  }
  return 0;
}
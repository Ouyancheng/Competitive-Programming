#include<iostream>

using namespace std;

int n,q,a;
int map[100001];
long long x,y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    map[a] = i;
  }
  cin >> q;
  for(int i = 0; i < q; i++) {
    cin >> a;
    x += (map[a] + 1), y += (n - map[a]);
  }
  cout << x << " " << y << "\n";
  return 0;
}
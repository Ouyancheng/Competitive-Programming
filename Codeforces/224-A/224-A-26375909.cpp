#include<iostream>

using namespace std;

int a,b,c;
int in[10001],my[10001];

int main() {
  cin >> a >> b >> c;
  in[a]++, in[b]++, in[c]++;
  for(int i = 1; i <= 10000; i++) {
    for(int j = 1; j <= 10000; j++) {
      if(i * j > 10000) break;
      for(int k = 1; k <= 10000; k++) {
        if(i * k > 10000 || j * k > 10000) break;
        my[i*j]++, my[j*k]++, my[i*k]++;
        if(my[i*j] == in[i*j] && my[j*k] == in[j*k] && my[i*k] == in[i*k]) {
          cout << 4*(i + j + k) << endl;
          return 0;
        } else {
          my[i*j]=my[j*k]=my[i*k]=0;
        }
      }
    }
  }
  return 0;
}
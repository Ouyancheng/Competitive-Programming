#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[(int) 1e5];
int n, hi;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
      scanf("%d",&arr[i]);
    hi = *max_element(arr,arr+n);
    printf("%d\n",count(arr,arr+n,hi));
    return 0;
}

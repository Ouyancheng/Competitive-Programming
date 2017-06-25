#include<stdio.h>

int n, num[500000];
long long sum,ans,cur,dp;

int main(void) {
  scanf("%d",&n);
  for(int i = 0; i < n; i++) {
    scanf("%d",&num[i]);
    sum += num[i];
  }
  if(sum % 3 == 0) {
    for(int i = 0; i < n-1; i++) {
      cur += num[i];
      if(cur == 2*sum/3) {
        ans += dp;
      }
      if(cur == sum/3) {
      	dp++;
      }
    }
  }
  printf("%lld\n",ans);
  return 0;
}
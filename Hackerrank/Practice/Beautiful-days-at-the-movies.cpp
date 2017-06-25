#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int reverse(int x) {
    int xx = 0;
    while(x > 0) {
        xx *= 10;
        xx += x%10;
        x /= 10;
    }
    return xx;
}

int l,r,k;
int sum;

int main() {
    scanf("%d %d %d",&l,&r,&k);
    for(int i = l; i <= r; i++) {
        int rev = reverse(i);
        sum += (((int) (abs(rev-i))) % k == 0);
    }
    printf("%d\n",sum);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

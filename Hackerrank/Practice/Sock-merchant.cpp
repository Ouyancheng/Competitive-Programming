#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int f[101];
int sum;

int main(){
    int n; 
    scanf("%d",&n);
    int *c = malloc(sizeof(int) * n);
    for(int c_i = 0; c_i < n; c_i++){
       scanf("%d",&c[c_i]);
        f[c[c_i]]++;
    }
    for(int i = 1; i <= 100; i++) {
        sum += f[i]/2;
    }
    printf("%d\n",sum);
    return 0;
}

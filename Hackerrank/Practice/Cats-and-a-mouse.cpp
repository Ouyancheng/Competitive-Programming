#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int q; 
    scanf("%d",&q);
    for(int a0 = 0; a0 < q; a0++){
        int x; 
        int y; 
        int z; 
        scanf("%d %d %d",&x,&y,&z);
        int distA = (int) abs(x-z);
        int distB = (int) abs(y-z);
        if(distA > distB) {
            printf("Cat B");
        } else if(distA < distB) {
            printf("Cat A");
        } else {
            printf("Mouse C");
        }
        printf("\n");
    }
    return 0;
}

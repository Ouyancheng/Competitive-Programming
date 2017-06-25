#include<bits/stdc++.h>

using namespace std;

int main(){
    int T; 
    scanf("%d",&T);
    for(int a0 = 0; a0 < T; a0++){
        int n;
        bool flag = false;
        scanf("%d",&n);
        int q[100005];
        for(int q_i = 0; q_i < n; q_i++){
           scanf("%d",&q[q_i]);
            if(q[q_i] - (q_i+1) > 2) {
                flag = true;
            }
        }
        if(flag) {
            printf("Too chaotic\n");
        } else {
            int swaps = 0;
            for(int i = n-1; i >= 1; i--) {
                flag = false;
                for(int j = 0; j < i; j++) {
                    if(q[j] > q[j+1]) {
                        swap(q[j],q[j+1]);
                        swaps++;
                        flag = true;
                    }
                }
                if(!flag) break;
            }
            printf("%d\n",swaps);
        }
        // your code goes here
    }
    return 0;
}

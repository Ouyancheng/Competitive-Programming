#include <cstdio>
#include <algorithm>
#include <cstdlib>

typedef long long ll;

int y[200010];
int n;
ll f,b;

ll cost(int x){
    ll res=0;
    for(int i=0;i<n;i++){
        res+=x;
        if(y[i]>x) res+=((ll)(y[i]-x)*(y[i]-x));
    }
    return(res);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&y[i]);
    }
    //printf("%d\n", y[0]);
    std::sort(y,y+n);
    int top=y[n-1];
    int bot = 0, mid = 0;
    while(bot < top - 1) {
        mid=(bot+top)/2;
        f = cost(mid + 1), b = cost(mid);
        if(f <= b) {
            bot = mid;
        } else {
            top = mid;
        }
    }
    printf("%lld\n",std::min(cost(bot),cost(top)));
    return 0;
}
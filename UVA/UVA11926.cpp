#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

#define repn(i,e) for(int i = 0; i < e; i++)
#define repsn(i,s,e) for(int i = s; i < e; i++)
#define rrepn(i,s) for(int i = s; i >= 0; i--)
#define rrepsn(i,s,e) for(int i = s; i >= e; i--)

bool DRAFT = 1;

int arr[1000005];
int a, b, n, m, c, ok;

int main(void) {
    while (scanf("%d %d", &n, &m) && (n | m)) {
        memset(arr, 0, sizeof (arr));
        ok = 1;

        repn(i, n) {
            scanf("%d %d", &a, &b);
            if (!ok) continue;

            repsn(j, a, b) {
                if (ok && arr[j]) {
                    ok = 0;
                    break;
                } else {
                    arr[j] = 1;
                }
            }
        }
        repn(i, m) {
            scanf("%d %d %d", &a, &b, &c);
            int s = a, d = b - a;
            while (ok && s < 1000000) {
                repsn(j, s, min(s + d, 1000000)) {
                    if (ok && arr[j]) {
                        ok = 0;
                        break;
                    } else {
                        arr[j] = 1;
                    }
                }
                s += c;
            }
        }
        if (ok) printf("NO CONFLICT");
        else printf("CONFLICT");
        printf("\n");
    }
    return 0;
}

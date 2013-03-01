#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1e-8
#define oo 1e9


using namespace std;

long long T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, anx, any, cx, cy;
long long d[5][2];

int main(){
        scanf("%I64d%I64d", &m, &n);
        scanf("%I64d%I64d", &e, &r);
        scanf("%I64d%I64d", &cx, &cy);
        if (m == e && n == r){
                puts("YES");
                return 0;
        }
        if (cx == 0 && cy == 0){
                puts("NO");
                return 0;
        }

        for (int i=0; i<4; i++){
                q = e; w = r;
                d[i][0] = e - m; d[i][1] = r - n;
                e = -w; r = q;
        }
        fi = 0;
        for (int i=0; i<4; i++){
                if (d[i][1]*cx - d[i][0]*cy % (cx*cx + cy*cy) == 0){
                        any = (d[i][1]*cx - d[i][0]*cy)/(cx*cx + cy*cy);
                        if (cx == 0 || ((d[i][0] + any*cy) % cx == 0)){
                                fi = 1;
                                break;
                        }
                } else continue;
        }
        if (fi == 1)
                puts("YES");
        else puts("NO");

        return 0;
}

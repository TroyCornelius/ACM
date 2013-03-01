#include <stdio.h>
#include <string.h>
int u[10010];
int dp[10010];
int f[10010][2];
int l[10010], w, r;
int p[10000], pn;
int ap[10000], apn;
int main(){
    int n, k, re, rx, t, ri = 1, s, x, y, i;
    while (scanf("%d%d", &n, &k) != EOF){
        if (n < k){
            printf("%d\n", n);
            continue;
        }
        if (n == k){
            printf("10\n");
            continue;
        }
        re = 1<<30;
        for (i = 1; i < k; i++){
            t = i;
            s = 1;
            u[0] = ri;
            while (u[t] != ri){
                u[t] = ri;
                s++;
                t = (t * k + i) % n;
            }
            if (t == 0){
                if (s < re){
                    re = s;
                    rx = i;
                }
            }
            ri++;
        }
        if (re == (1<<30)){
            int ry;
            for (x = 0; x < k; x++){
                for (y = x + 1; y < k; y++){
                    memset(dp, -1, sizeof(dp));
                    w = 0;
                    r = 0;
                    if (x){
                        dp[x] = 1;
                        l[w++] = x;
                    }
                    dp[y] = 1;
                    l[w++] = y;
                    while (r < w){
                        int xx = l[r];
                        int yy = (xx * k + x) % n;
                        if (dp[yy] < 0){
                            dp[yy] = dp[xx] + 1;
                            f[yy][0] = xx;
                            f[yy][1] = x;
                            l[w++] = yy;
                        }
                        yy = (xx * k + y) % n;
                        if (dp[yy] < 0){
                            dp[yy] = dp[xx] + 1;
                            f[yy][0] = xx;
                            f[yy][1] = y;
                            l[w++] = yy;
                        }
                        if (dp[0] >= 0) break;
                        r++;
                    }
                    if (dp[0] >= 0 && dp[0] < re){
                        re = dp[0];
                        rx = x;
                        ry = y;
                        int xx = 0;
                        apn = 0;
                        while (dp[xx] > 1){
                            ap[apn++] = f[xx][1];
                            xx = f[xx][0];
                        }
                        ap[apn++] = xx;
                    }else if (dp[0] >= 0 && dp[0] == re){
                        int xx = 0;
                        pn = 0;
                        while (dp[xx] > 1){
                            p[pn++] = f[xx][1];
                            xx = f[xx][0];
                        }
                        p[pn++] = xx;
                        for (i = pn - 1; i >= 0; i--){
                            if (ap[i] != p[i]) break;
                        }
                        if (ap[i] > p[i]){
                            for (i = 0; i < pn; i++) ap[i] = p[i];
                        }
                    }
                }
            }
            while (apn--) printf("%d", ap[apn]);
            printf("\n");
        }else{
            while (re--) printf("%d", rx);
            printf("\n");
        }
    }
    return 0;
}
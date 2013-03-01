#include <cstdio>
#include <cstring>

const int MAXN = 20;
struct SS {int dps, hp;} a[MAXN];
int sum[1<<MAXN], dp[1<<MAXN];
int n;

int main() {
  //  freopen("data.in","r",stdin);
  //  freopen("data.out","w",stdout);
    while (scanf("%d",&n) != EOF) {
        for (int i = 0 ; i < n ; i++)
            scanf("%d%d",&a[i].dps,&a[i].hp);
        memset(sum, 0, sizeof(sum));
        for (int mask = 0 ; mask < (1<<n) ; ++mask)
            for (int i = 0 ; i < n ; i++)
                if (mask&(1<<i)) sum[mask] += a[i].hp;
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int mask = 0 ; mask < (1<<n) ; ++mask) {
            for (int i = 0 ; i < n ; i++) {
                if (mask & (1<<i)) continue;
                int tmask = mask + (1<<i);
                int cost = dp[mask] + sum[tmask] * a[i].dps;
                if (cost < dp[tmask]) dp[tmask] = cost;
            }
        }
        printf("%d\n", dp[(1<<n)-1]);
    }
    return 0;
}


#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN = 128;
struct SS {int dps, hp;} a[MAXN];
int vis[MAXN], ans[MAXN];
int n;

int main() {
    freopen("hero.in","r",stdin);
    freopen("hero.out.wrong","w",stdout);
    while (scanf("%d",&n) != EOF) {
        int tot_time = 0, tot_dps = 0;
        for (int i = 0 ; i < n ; i++) {
            scanf("%d%d",&a[i].dps,&a[i].hp);
            tot_time += a[i].hp;
            tot_dps += a[i].dps;
        }
        memset(vis, 0, sizeof(vis));
        for (int iter = 0 ; iter < n ; iter++) {
            double best = -1;
            // int best = -1;
            int besti;
            for (int i = 0 ; i < n ; i++) {
                if (vis[i]) continue;
                // int tmp = (tot_time - a[i].hp) * a[i].dps;
                double tmp = a[i].dps / a[i].hp;
                if (tmp > best) {
                    best = tmp;
                    besti = i;
                }
            }
            ans[iter] = besti;
            vis[besti] = 1;
            tot_time -= a[besti].hp;
        }
        int res = 0;
        for (int iter = 0 ; iter < n ; ++iter) {
            int id = ans[iter];
            res += a[id].hp * tot_dps;
            tot_dps -= a[id].dps;
        }
        printf("%d\n", res);
    }
    return 0;
}

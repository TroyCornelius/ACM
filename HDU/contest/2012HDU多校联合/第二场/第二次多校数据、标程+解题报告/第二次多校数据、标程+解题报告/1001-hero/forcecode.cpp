#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 128;
const int INF = 1000100100;
struct SS {int dps, hp;} a[MAXN];
int ans[MAXN], p[MAXN], n;

int main() {
    freopen("hero.in","r",stdin);
    freopen("hero.out.bf","w",stdout);
    while (scanf("%d",&n) != EOF) {
        for (int i = 0 ; i < n ; i++) {
            scanf("%d%d",&a[i].dps,&a[i].hp);
            p[i] = i;
        }
        if (n > 10) {
            printf("too big data\n");
            continue;
        }
        int best = INF;
        do {
            int tot_dps = 0;
            for (int i = 0 ; i < n ; i++)
                tot_dps += a[i].dps;
            int res = 0;
            for (int iter = 0 ; iter < n ; ++iter) {
                int id = p[iter];
                res += a[id].hp * tot_dps;
                tot_dps -= a[id].dps;
            }
            if (res < best) best = res;
        } while (next_permutation(p, p+n));
        printf("%d\n",best);
    }
    return 0;
}

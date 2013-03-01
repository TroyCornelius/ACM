#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

const int MAXN = 100010;
int a[MAXN], n;

int main() {
    freopen("1010.in","r",stdin);
    freopen("forcedata.out","w",stdout);
    while (scanf("%d",&n) != EOF) {
        assert(n >= 1 && n <= 100000);
        for (int i = 0 ; i < n ; i++) {
            scanf("%d",&a[i]);
            assert(a[i] >= -1000 && a[i] <= 1000);
        }
        double best = -1e100;
        int best_st, best_ed;
        for (int st = 0 ; st < n ; ++st) {
            int sum = 0;
            for (int ed = st ; ed < n ; ++ed) {
                sum += a[ed];
                double tmp = ((double)sum * sum) / (ed-st+1);
                if (tmp > best) {
                    best = tmp;
                    best_st = st;
                    best_ed = ed;
                }
            }
        }
        // printf("%.6lf %d %d\n", best, best_st, best_ed);
        printf("%.2lf\n", best);
    }
    return 0;
}

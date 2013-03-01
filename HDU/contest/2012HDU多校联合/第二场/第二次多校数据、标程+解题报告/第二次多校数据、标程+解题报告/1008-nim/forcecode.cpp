#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, a[20];
int ans;
int out[20], bestout[20];

void solve(int p, int cur_xor, int cur_cost) {
    if (p == n - 1) {
        if (cur_xor >= a[p]) {
            cur_cost += cur_xor - a[p];
            if (cur_cost < ans) {
                ans = cur_cost;
                memcpy(bestout, out, sizeof(out));
            }
        }
        return;
    }
    for (int k = 0 ; k < 50 ; ++k) {
        out[p] = k;
        solve(p+1, cur_xor ^ (a[p] + k), cur_cost + k);
    }
}

int main() {
    freopen("data.in","r",stdin);
    freopen("forcedata.out","w",stdout);
    while (scanf("%d",&n) != EOF) {
        for (int i = 0 ; i < n ; i++)
            scanf("%d",&a[i]);
        ans = 1000100100;
        solve(0, 0, 0);
        printf("%d\n",ans);
        // for (int i = 0 ; i < n ; i++)
        //     printf("a[%d]+%d\n",i,bestout[i]);
    }
    return 0;
}

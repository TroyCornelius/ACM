#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1000100100;
const int MAXN = 10;
const int MAXD = 22;
int a[MAXN];
int bt[MAXN][MAXD];
int n, m;
vector<int> tv[MAXN];
int dp[MAXD][1<<MAXN];
int vis[MAXD][1<<MAXN];

int solve(int,int);

void try_gen_mask(int dig, int idx, int mask, int cnt_one, int res_mask, int cost) {
    if (idx == n) {
        if (cnt_one % 2 == 0) {
            int res = solve(dig+1, res_mask);
            // printf("dig:%d idx:%d mask:%d cnt_one:%d res_mask:%d res:%d cost:%d\n", dig, idx, mask, cnt_one, res_mask, res, cost);
            if (res + cost < dp[dig][mask]) {
                dp[dig][mask] = res + cost;
            }
            // printf("dp[%d][%d] = %d\n", dig, mask, dp[dig][mask]);
        }
        return;
    }
    if (bt[idx][dig] == 0) {
        if (mask & (1 << idx)) {
            // carry
            try_gen_mask(dig, idx+1, mask, cnt_one, res_mask | (1 << idx), cost + (1 << (m - 1 - dig)));
        } else {
            // not carry
            try_gen_mask(dig, idx+1, mask, cnt_one+1, res_mask, cost + (1 << (m - 1 - dig)));
            try_gen_mask(dig, idx+1, mask, cnt_one, res_mask, cost);
            try_gen_mask(dig, idx+1, mask, cnt_one+1, res_mask | (1 << idx), cost);
        }
    } else {
        if (mask & (1 << idx)) {
            // carry
            try_gen_mask(dig, idx+1, mask, cnt_one, res_mask, cost + (1 << (m - 1 - dig)));
            try_gen_mask(dig, idx+1, mask, cnt_one+1, res_mask | (1 << idx), cost + (1 << (m - 1 - dig)));
            try_gen_mask(dig, idx+1, mask, cnt_one, res_mask | (1 << idx), cost);
        } else {
            // not carry
            try_gen_mask(dig, idx+1, mask, cnt_one+1, res_mask, cost);
        }
    }
}

int solve(int dig, int mask) {
    // printf("try solve (%d,%d)\n", dig, mask);
    if (vis[dig][mask]) return dp[dig][mask];
    vis[dig][mask] = 1;
    if (dig == m) {
        if (mask == 0) return dp[dig][mask] = 0;
        return dp[dig][mask] = INF;
    }
    try_gen_mask(dig, 0, mask, 0, 0, 0);
    // printf("dp[%d][%d]:%d\n", dig,mask,dp[dig][mask]);
    return dp[dig][mask];
}

int main() {
 //   freopen("data.in","r",stdin);
 //   freopen("data.out","w",stdout);
    while (scanf("%d",&n) != EOF) {
        memset(bt, 0, sizeof(bt));
        m = 0;
        for (int i = 0 ; i < n ; i++) {
            scanf("%d",&a[i]);
            tv[i].clear();
            while (a[i]) {
                tv[i].push_back(a[i]%2);
                a[i] /= 2;
            }
            if (tv[i].size() > m)
                m = tv[i].size();
        }
        ++m;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < tv[i].size() ; ++j)
                bt[i][m-1-j] = tv[i][j];
        /*
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++)
                printf(" %d", bt[i][j]);
            printf("\n");
        }
        */
        memset(dp, 0x3f, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        int ans = solve(0, 0);
        if (ans >= INF) printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3fffffff
#define LL long long
#define N 13
int n, m, k, need[N];
char dp[N + 1][1594325], go[N][1 << N];
int like[N][N];
int solve(int idx, int mask)
{
    if(dp[idx][mask] != -1)
        return dp[idx][mask];
    dp[idx][mask] = 0;
    if(idx == m)
    {
        dp[idx][mask] = 1;
    }
    else
    {
        int i, j, sub;
        for(sub = mask; sub != 0; sub = (sub - 1) & mask)
        {
            if(go[idx][sub])
            {
                dp[idx][mask] |= solve(idx + 1, mask ^ sub);
                if(dp[idx][mask])
                    return dp[idx][mask];
            }
        }
    }
    return dp[idx][mask];
}
int main()
{
    freopen("out_for_in.txt", "r", stdin);
    freopen("ppout.txt", "w", stdout);
    int t, cas = 1, i, j, p;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &need[i]);
        }
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &like[i][j]);
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(go, 0, sizeof(go));
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < (1 << n); j++)
            {
                int val = 0;
                for(p = 0; p < n; p++)
                {
                    if(j & (1 << p))
                    {
                        if(like[i][p])  val += k;
                        else            val += 1;
                    }
                }
                if(val >= need[i])  go[i][j] = 1;
            }
        }
        int ans = solve(0, (1 << n) - 1);
        printf("Case #%d: %s\n", cas++, ans ? "YES" : "NO");
    }
    return 0;
}

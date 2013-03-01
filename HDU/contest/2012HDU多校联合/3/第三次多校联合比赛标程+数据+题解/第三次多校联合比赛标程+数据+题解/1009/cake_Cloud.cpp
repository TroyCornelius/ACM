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
#define N 1005
struct Node
{
    int h, w;
    void init(int _h, int _w)
    {
        h = _h, w = _w;
    }
};
int n, m, ht[2][N][N], ig[N][N], dp[N][N];
Node sta[N];
int top;
char g[N][N];
int solve_square()
{
    int i, j, ret = 0;
    for(i = 0; i < n; i++)
        dp[i][0] = 1;
    for(j = 0; j < m; j++)
        dp[0][j] = 1;
    for(i = 1; i < n; i++)
    {
        for(j = 1; j < m; j++)
        {
            dp[i][j] = 1;
            if(ig[i][j - 1] != ig[i][j] && ig[i - 1][j] != ig[i][j])
            {
                int mv = min(dp[i][j - 1], dp[i - 1][j]);
                if(ig[i][j] == ig[i - mv][j - mv])
                    dp[i][j] = mv + 1;
                else
                    dp[i][j] = mv;
            }
            ret = max(ret, 4 * dp[i][j]);
        }
    }
    return ret;
}
int solve_rectangle()
{
    int i, j, k, ret = 0;
    memset(ht, 0, sizeof(ht));
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            k = ig[i][j];
            ht[k][i][j] = 1;
            if(i)   ht[k][i][j] += ht[k][i - 1][j];
        }
    }
    for(k = 0; k < 2; k++)
    {
        for(i = n - 1; i >= 0; i--)
        {
            top = 0;
            sta[top++].init(-1, 1);

            for(j = 0; j < m; j++)
            {
                int width = 1;
                while(sta[top - 1].h >= ht[k][i][j])
                {
                    width += sta[top - 1].w;
                    if(sta[top - 1].h > 0)
                        ret = max(ret, 2 * (sta[top - 1].h + sta[top - 1].w));
                    top--;
                }
                sta[top++].init(ht[k][i][j], width);
            }
            while(top > 0)
            {
                if(sta[top - 1].h > 0)
                    ret = max(ret, 2 * (sta[top - 1].h + sta[top - 1].w));
                top--;
            }
        }
    }
    return ret;
}
int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("myoutput.txt" , "w" , stdout);

    int t, i, j, cas = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++)
        {
            scanf("%s", g[i]);
            for(j = 0; j < m; j++)
            {
                ig[i][j] = (g[i][j] == 'R');
            }
        }
        int ans = max(solve_square(), solve_rectangle());
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

int n, g[17][17], sum[20], ans;
bool lc[40], rc[40];
bool col[20];
int start;
void dfs(int k, int tot)
{
    if (clock() - start > 1.2 * CLOCKS_PER_SEC) return;
    if (k <= 0) 
    {
        if (ans < tot) ans = tot;
        return;
    }
    if (tot + sum[k] <= ans) return; 
    for(int i = n; i >= 1; --i)
    if (!col[i] && !lc[k+i-1] && !rc[n+k-i])
    {
        //col |= (1<<i);
        col[i] = true;
        lc[k+i-1] = true; rc[n+k-i] = true;
        //tot += g[k][i];
        //if (tot + g[k][i] + sum[k-1] <= ans) continue;
        dfs(k-1, tot + g[k][i]);
        //tot -= g[k][i];
        col[i] = false;
        //col ^= (1<<i); 
        lc[k+i-1] = false; rc[n+k-i] = false;
    }
    return;
}
inline int getint()
{
    char c = getchar();
    int t = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
   {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}

int main() 
{
    int T;
    //sf("%d", &T);
    T = getint();
    while (T--)
    {
        n = getint();
        //sf("%d", &n);
        //FOR(i, 1, n+1)
            //FOR(j, 1, n+1)
        for (int i = 1; i<=n; ++i)
            for (int j = 1; j<=n; ++j)
                g[i][j] = getint();
            //sf("%d", &g[i][j]);
        sum[0] = 0;
        for (int i = 1; i<= n; i++) sum[i] = sum[i-1] + g[i][n];
        ans = 0;
        memset(col, false, sizeof(col));
        memset(lc, false, sizeof(lc));
        memset(rc, false, sizeof(rc));
        start = clock();
        dfs(n, 0);
        printf("%d\n", ans);
    }
    return 0;
}


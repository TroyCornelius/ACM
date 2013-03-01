#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, opt, f, m, r, ans, k[60];
bool vis[3000], g[3000], a[3000];

void dfs(int t, int p, int w)
{
     if (g[t]) return;
     if (vis[t]) ans = 1;
     if (ans) return;
     vis[t] = true;
     if (!a[t])
     {
               for (int i = 0; i < opt; i++)
               {
                   if (t - k[i] <= 0) continue;
                   dfs(t - k[i], i, w + 1);
                   if (ans) return;
               }
               g[t] = true;
     }
     else
     {
         dfs(t + m, p, w + 1);
         g[t] = g[t + m];
     }
}
     
int main()
{
    scanf("%d%d%d%d", &n, &opt, &f, &m);
    for (int i = 0; i < opt; i++) scanf("%d", &k[i]);
    memset(a, false, sizeof(a));
    memset(g, false, sizeof(g));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < f; i++)
    {
        scanf("%d", &r);
        a[r] = true;
    }
    ans = 0;
    dfs(n, 0, 0);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
    

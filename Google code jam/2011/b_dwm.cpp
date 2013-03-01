#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

char q[110], cb[50][10], s[10], a[110];
int t, c, d, n, ed, u, v;
bool chk, g[50][50];

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(g, false, sizeof(g));
        scanf("%d", &c);
        for (int i = 0; i < c; i++)
            scanf("%s", cb[i]);
        scanf("%d", &d);
        while (d--)
        {
              scanf("%s", s);
              u = s[0] - 'A';
              v = s[1] - 'A';
              g[u][v] = g[v][u] = true;
        }
        scanf("%d", &n);
        scanf("%s", a);
        ed = -1;
        for (int i = 0; i < n; i++)
        {
            q[++ed] = a[i];
            chk = true;
            while (ed > 0 && chk)
            {
                  chk = false;
                  for (int j = 0; j < c; j++)
                      if (q[ed] == cb[j][0] && q[ed - 1] == cb[j][1] || q[ed] == cb[j][1] && q[ed - 1] == cb[j][0])
                      {
                                q[--ed] = cb[j][2];
                                chk = true;
                                break;
                      }
            }
            for (int j = 0; j < ed; j++)
                if (g[q[j] - 'A'][q[ed] - 'A'])
                {
                                       ed = -1;
                                       break;
                }
        }
        printf("Case #%d: [", cas);
        for (int i = 0; i < ed; i++)
            printf("%c, ", q[i]);
        if (ed >= 0) printf("%c", q[ed]);
        printf("]\n");
    }        
    return 0;
}

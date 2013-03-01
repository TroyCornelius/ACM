#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 999999999
#define Maxn 110
using namespace std;
int n, d, m;
int member[Maxn][3];
int g[Maxn][Maxn];
int f[Maxn][Maxn][5];
int main()
{
    int u, v;
    while (scanf("%d%d", &n, &d) != EOF)
    {
        for (int i=0; i<=n; i++)
          for (int j=0; j<=n; j++)
            g[i][j] = inf;
        for (int i=0; i<n; i++)
        {
            scanf("%d%d%d", &member[i][0], &member[i][1], &member[i][2]);
            scanf("%d", &m);
            for (int j=0; j<m; j++)
            {
                scanf("%d%d", &u, &v);
                g[i][u] = v;                                
            }       
        }        
        for (int k=0; k<n; k++)
          for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            if (g[i][k]+g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
            
        for (int i=0; i<=d; i++)
          for (int j=0; j<=n; j++)
            for (int k=0; k<=3; k++)
              f[i][j][k] = -inf;
        
        f[1][0][0] = 0;
        for (int i=1; i<d; i++)
          for (int j=0; j<n; j++)
            for (int k=0; k<3; k++)
            {
                f[i][j][k] += member[j][k];
                if (k < 2) f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k]);
                else f[i+1][j][2] = max(f[i+1][j][2], f[i][j][k]);
                
                for (int p=0; p<n; p++)
                if (f[i][j][k] >= g[j][p]) f[i+1][p][0] = max(f[i+1][p][0], f[i][j][k]-g[j][p]);
            }
        int ans = 0;
        for (int i=0; i<n; i++) 
          for (int k=0; k<3; k++)
            ans = max(ans, f[d][i][k]);
        printf("%d\n", ans); 
    }    
    return 0;
    }

#include <iostream>
#include <vector>
#define Maxn 105
using namespace std;

int app[Maxn], n, k, f[Maxn][Maxn*2], g[Maxn][Maxn*2];
vector <int> adj[Maxn];


void dfs(int x, int fa)
{
     for (int i=0; i<adj[x].size(); i++)
     if (adj[x][i] != fa)
       {
           int j = adj[x][i];
           dfs(j, x);
           for (int t=k; t>=2; t--) g[j][t] = g[j][t-2] + app[j];
             
       }
    
    
     }
int main()
{
     int a, b;
     while (scanf("%d%d", &n, &k) != EOF)
       {
           for (int i=1; i<=n; i++) scanf("%d", &app[i]);
           for (int i=0; i<=n; i++) adj[i].clear();
           for (int i=0; i<n-1; i++)
             {
                scanf("%d%d", &a, &b);
                adj[a].push_back(b);
                adj[b].push_back(a);                    
             }      
          memset(f, 0, sizeof(f));
          memset(g, 0, sizeof(g)); 
          dfs(1, 1);
          printf("%d\n", f[1][k] + app[1]);    
       }
    
    
    
    
    return 0;
    }

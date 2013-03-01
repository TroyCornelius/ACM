#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define pb push_back
#define Maxn 550
#define Maxm 70500
#define inf 1<<30
using namespace std;
typedef vector<int>::const_iterator vi;
int n, m;
int d[Maxn][Maxn];
int min_t, px, py;
struct Query
{
       char s[2];
       int x, y;
       }q[Maxm];
vector<int> e[Maxn];
bool dfs(int u, int v, int fa)
{
     if (u == v) return true;
     for (vi i=e[u].begin(); i!=e[u].end(); i++)
     {
         if (*i != fa && dfs(*i, v, u))
         {
            if (min_t > d[u][*i])
            {
               min_t = d[u][*i];
               px = u; py = *i;                    
            }         
            return true;           
         }         
     }
     return false;
     }
int main()
{
    int a, b, ca=0, tx, ty;
    while (scanf("%d%d", &n, &m) != EOF)
    {
          for (int i=0; i<=n; i++)
          {
              e[i].clear();
              fill(d[i], d[i]+n+1, inf);              
          }
          for (int i=0; i<m; i++)
          {
              scanf("%s%d%d", q[i].s, &q[i].x, &q[i].y);
              if (q[i].s[0] == 'D') d[q[i].x][q[i].y] = d[q[i].y][q[i].x] = i;              
          }
          if (ca) printf("\n");
          printf("Case %d:\n", ++ca);
          for (int i=0; i<m; i++)
          {
              tx = q[i].x; ty = q[i].y;
              if (q[i].s[0]=='I')
              {
                  min_t = inf;
                  if (dfs(tx, ty, -1))
                  {
                       if (min_t < d[tx][ty])
                       {
                           e[px].erase(remove(e[px].begin(), e[px].end(), py), e[px].end());
                           e[py].erase(remove(e[py].begin(), e[py].end(), px), e[py].end());
                           e[tx].pb(ty);
                           e[ty].pb(tx);                                 
                       }                              
                  }
                  else
                  {
                      e[tx].pb(ty);
                      e[ty].pb(tx);                      
                  }     
              }
              else
              if (q[i].s[0] == 'D')
              {                  
                  e[tx].erase(remove(e[tx].begin(), e[tx].end(), ty), e[tx].end());
                  e[ty].erase(remove(e[ty].begin(), e[ty].end(), tx), e[ty].end());                                 
              }
              else printf("%s\n", dfs(tx, ty, -1) ? "YES":"NO");       
          }
    }
    return 0;
    }

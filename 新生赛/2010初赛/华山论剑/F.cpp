#include <iostream>
#include <vector>
#define oo 99999999
using namespace std;

struct Tnode
{
       int id, ti;
       Tnode(int a, int b)
         {id=a; ti=b;}
       };
int g[105][105], bell[105][105];
int n, m, time_lim, T;
int val[110], st, en, ans_mon, ans_time;
bool used[110], flag;
void init()
{
     scanf("%d%d%d", &n, &m, &time_lim);
     for (int i=1; i<=n; i++) scanf("%d", &val[i]);
     for (int i=0; i<=n; i++)
       for (int j=0; j<=n; j++)
         g[i][j] = oo;     
     int x, y, c;
     for (int i=0; i<m; i++)
       {
          scanf("%d%d%d", &x, &y, &c);        
          g[x][y] <?= c; 
          g[y][x] <?= c;
       }
     memcpy(bell, g, sizeof(g));
     scanf("%d%d", &st, &en);
     memset(used, false, sizeof(used));
     ans_mon = ans_time = 0;
     }
void bellman_ford()
{
     for (int k=1; k<=n; k++)
       for (int i=1; i<=n; i++)
         for (int j=1; j<=n; j++)
           {
             if (bell[i][k] + bell[k][j] < bell[i][j])
               bell[i][j] = bell[i][k] + bell[k][j];                  
           }     
     }
void dfs(int pi, int mon, int cost_time)
{
      if (cost_time > time_lim) return;
     if (pi == en)
       {
          if (mon > ans_mon)
            {
               ans_mon = mon;
               ans_time = cost_time;                  
            }
          else
          if (mon == ans_mon) ans_time <?= cost_time;
          return;            
       }

     if (bell[pi][en] + cost_time > time_lim) return;
     
     
     for (int i=2; i<=n; i++)
       if (i!= pi && g[pi][i] != oo && !used[i])
         {
            used[i] = true;            
            dfs(i, mon+val[i], cost_time+g[pi][i]);
            used[i] = false;     
         }     
     return ;
     }
int main()
{
    scanf("%d", &T);
    for (; T>0; T--)
      {
         init();       
         bellman_ford();  
         used[st] = true;
         dfs(st, val[st], 0);  
         printf("%d %d\n", ans_mon, ans_time);
      }
    system("pause");
    return 0;
    }

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>
#include <cmath>
using namespace std;

int T, n, m;
int ans;
vector<int> ret;
int nxt[200];
bool vis[200], g[50][50];
struct Twall
{
       int u, v;       
       }d[2005];
void init()
{
     scanf("%d%d", &n, &m);
     for (int i=0; i<m; i++) scanf("%d", &d[i].u);
     for (int i=0; i<m; i++) scanf("%d", &d[i].v);     
     ans = n;
     memset(vis, false, sizeof(vis));
     memset(g, false, sizeof(g));
     for (int i=0; i<m; i++)
     {
         vis[d[i].u] = true;  vis[d[i].v] = true;
         g[d[i].u][d[i].v] = g[d[i].v][d[i].u] = true;
         int tmp = min(n+d[i].u-d[i].v+1, d[i].v - d[i].u + 1);
         ans <?= tmp;         
     }
     }
bool check()
{
     bool col[10];
     
     for (int i=0; i<m; i++)
     {
         memset(col, false, sizeof(col));
         for (int j=d[i].u; j<=d[i].v; j++) col[ret[j-1]] = true;
         for (int p=1; p<=ans; p++)
         if (!col[p]) return false;
         
         memset(col, false, sizeof(col));
         int y = d[i].v;
         while (y != d[i].u+1)
         {
           col[ret[y-1]] = true;
           y++;
           if (y>n) y = 1;               
         }
         for (int p=1; p<=ans; p++)
         if (!col[p]) return false;   
     }     
     return true;     
     }
void work()
{
     ret.clear();
     int tot=0, num=1;
     while (tot<n)
     {
        ret.push_back(num);
        num++;
        if (num > ans) num = 1;
        tot++;           
     }
     sort(ret.begin(), ret.end());
     while (true)
     {
        if (check()) 
        {
           for (int i=0; i<ret.size()-1; i++) printf("%d ", ret[i]);
           printf("%d\n", ret[ret.size()-1]);
           return;                     
        }
        else 
        {
             bool flag = next_permutation(ret.begin(), ret.end());
             if (!flag) return;
        }
     }
     }
int main()
{
  //  freopen("C-small-attempt0.in", "r", stdin);
  //  freopen("C-small-attempt0.out", "w", stdout);
    cin >>T;
    for (int t=1; t<=T; t++)
    {
        init();
        printf("Case #%d: %d\n", t, ans);
        work();
    }
    
   
    return 0;
    }

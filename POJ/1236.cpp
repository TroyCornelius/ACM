#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#define Maxn 110
#define pb push_back
using namespace std;


int n, ans1, ans2, tot, line[Maxn];
int id[Maxn], m, in[Maxn], out[Maxn];
vector<int> g[Maxn], g2[Maxn];
bool vis[Maxn];
void dfs1(int x)
{
     vis[x] = true;
     for (int i=0; i<g[x].size(); i++)
     if (!vis[g[x][i]]) dfs1(g[x][i]);
     line[tot++] = x;
     }
void dfs2(int x)
{
     id[x] = m;
     for (int i=0; i<g2[x].size(); i++)
     if (!id[g2[x][i]]) dfs2(g2[x][i]);     
     }
int main()
{
    int v;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        while (scanf("%d", &v) && v)
        {
           g[i].pb(v);
           g2[v].pb(i);
        }
    }
    tot = 0;
    memset(vis, false, sizeof(vis));
    for (int i=1; i<=n; i++)
    if (!vis[i]) dfs1(i);
    memset(id, 0, sizeof(id));
    m = 0;
    for (int i=tot-1; i>=0; i--)
    if (!id[line[i]]) 
    {
       ++m;
       dfs2(line[i]);                      
    }
    ans1 = ans2 = 0;
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for (int i=1; i<=n; i++)
      for (int j=0; j<g[i].size(); j++)
      if (id[i] != id[g[i][j]])
      {
          in[id[g[i][j]]]++;
          out[id[i]]++;
      }
    for (int i=1; i<=m; i++)
    {
        if (!out[i]) ans2++;
        if (!in[i]) ans1++;        
    }
    if (m == 1) printf("1\n0\n");
    else printf("%d\n%d\n", ans1, max(ans1, ans2));   
    return 0;
    }

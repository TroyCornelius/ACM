#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#define Maxn 10000
#define pb push_back
using namespace std;


int n, m, tot, line[Maxn];
int id[Maxn], out[Maxn], cnt;
bool vis[Maxn];
vector<int> g[Maxn], g2[Maxn];
void dfs1(int x)
{
     vis[x] = true;
     for (int i=0; i<g[x].size(); i++) if (!vis[g[x][i]]) dfs1(g[x][i]);
     line[tot++] = x;     
     }
void dfs2(int x)
{
     id[x] = cnt;
     for (int i=0; i<g2[x].size(); i++) if (!id[g2[x][i]]) dfs2(g2[x][i]);
     }
int main()
{
    int a, b;
    while (~scanf("%d", &n) && n)
    {
       for (int i=0; i<=n; g[i].clear(), g2[i].clear(), i++);
       scanf("%d", &m);
       for (int i=0; i<m; i++)
       {
           scanf("%d%d", &a, &b);
           g[a].pb(b);
           g2[b].pb(a);
       }
       tot = 0; cnt = 0;
       memset(vis, false, sizeof(vis));
       memset(id, 0, sizeof(id));
       memset(out, 0, sizeof(out));
       for (int i=1; i<=n; i++) if (!vis[i]) dfs1(i);
       for (int i=tot-1; i>=0; i--) if (!id[line[i]]) {cnt++; dfs2(line[i]);}
       for (int i=1; i<=n; i++)
         for (int j=0; j<g[i].size(); j++)
         if (id[i] != id[g[i][j]]) out[id[i]]++;
       vector<int> ans;
       for (int i=1; i<=cnt; i++)
       if (out[i] == 0)
         for (int j=1; j<=n; j++) if (id[j] == i) ans.pb(j);
       sort(ans.begin(), ans.end());
       for (int i=0; i<ans.size()-1; i++) printf("%d ", ans[i]);
       printf("%d\n", ans[ans.size()-1]);          
    }  
    
    return 0;
    }

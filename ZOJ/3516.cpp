#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#define Maxn 10010
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, less<int> > PQ;
int n, v[Maxn];
vector<int> f[Maxn];
vector<int> adj[Maxn];
bool vis[Maxn];

void dfs(int rt, int fa)
{
     vis[rt] = true;
     if (adj[rt].size() == 1 && adj[rt][0] == fa) {f[rt].pb(v[rt]); return;}
     PQ q;
     q.push(v[rt]);
     for (int i=0; i<adj[rt].size(); i++)
     {
         int id = adj[rt][i];
         if (!vis[id] && id != fa) {dfs(id, rt);
         for (int j=0; j<f[id].size(); j++) q.push(f[id][j]);}
     }
     int cnt = 0;
     while (!q.empty() && cnt < 3)
     {
        f[rt].pb(q.top());
        q.pop();
        cnt++;           
     }
     sort(f[rt].begin(), f[rt].end(), greater<int>());
     return ;     
     }
int main()
{
    int b, m;
    while (scanf("%d", &n) != EOF)
    {
       scanf("%d", &v[0]);
       for (int i=0; i<=n; i++) {adj[i].clear();f[i].clear();}
       memset(vis, false, sizeof(vis));
       for (int i=1; i<n; i++)
       {
           scanf("%d%d", &b, &v[i]);
           adj[i].pb(b);
           adj[b].pb(i);           
       }
       dfs(0, -1);    
       scanf("%d", &m);
       for (int i=0; i<m; i++)
       {
           scanf("%d", &b);
           if (f[b].size() < 3) printf("-1\n");
           else
           {
               printf("%d %d %d\n", f[b][0], f[b][1], f[b][2]);               
           }           
       }
    }
    
  //  system("pause");
    return 0;
    }

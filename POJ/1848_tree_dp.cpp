#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#define inf 99999999
#define Maxn 110
#define pb push_back
using namespace std;

int n;
vector<int> adj[Maxn];
int f[Maxn][3];
bool vis[Maxn];


void dfs(int rt)
{
     vector<int> child;
     child.clear();
     vis[rt] = true;
    // cout <<rt <<endl;
     for (int i=0; i<adj[rt].size(); i++)
     {
         if (!vis[adj[rt][i]])
         {
            child.pb(adj[rt][i]);
            dfs(adj[rt][i]);
         }         
     }
     
     if (!child.size())
     {
        f[rt][0] = inf; f[rt][1] = 0; f[rt][2] = inf;   
        return;               
     }
     int sum = 0, s;
     for (int i=0; i<child.size(); i++) sum += f[child[i]][0];
     f[rt][1] = min(f[rt][1], sum);
     
     for (int i=0; i<child.size(); i++)
     {
         s = sum - f[child[i]][0];
         f[rt][2] = min(f[rt][2], s + min(f[child[i]][1], f[child[i]][2]));
         f[rt][0] = min(f[rt][0], s + f[child[i]][2] + 1);         
     }
     
     for (int i=0; i<child.size()-1; i++)
     {
         for (int j=i+1; j<child.size(); j++)
         {
             s = sum - f[child[i]][0] - f[child[j]][0];
             f[rt][0] = min(f[rt][0], min(f[child[i]][1], f[child[i]][2]) + min(f[child[j]][1], f[child[j]][2]) + s + 1); 
         }         
     }
     return ;     
     }
void dp()
{
     for (int i=0; i<=n; i++) f[i][0] = f[i][1] = f[i][2] = inf;
     memset(vis, false, sizeof(vis));
     dfs(1);
     if (f[1][0] == inf) printf("-1\n");
     else printf("%d\n", f[1][0]);     
     }
int main()
{
    int a, b;
    scanf("%d", &n);    
    for (int i=0; i<n-1; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dp();
    system("pause");
    return 0;  
    }

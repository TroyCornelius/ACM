#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
#define Maxn 50050
#define pb push_back
#define oo 999999999
using namespace std;


int n, minp, maxp, dis[Maxn];
struct Tnode
{
       int id,len;
       Tnode(int a, int b)
       :id(a),len(b){}
       };
vector<Tnode> adj[Maxn];
queue<int> q;
bool vis[Maxn];
void spfa()
{
     dis[minp] = 0;
     memset(vis, false, sizeof(vis));
     q.push(minp);
     while (!q.empty())
     {
        int now = q.front();
        vis[now] = false;
        q.pop();
        for (int i=0; i<adj[now].size(); i++)
        {
            int v = adj[now][i].id;
            int w = adj[now][i].len;
            if (dis[v] < dis[now]+w)
            {
               dis[v] = dis[now] + w;
               if (!vis[v])
               {
                   vis[v] = true;
                   q.push(v);           
               }                     
            }            
        }  
     }
     printf("%d\n", dis[maxp]);
     }
int main()
{
    int ai, bi, ci;
    scanf("%d", &n);
    minp = oo; maxp = 0;
    for (int i=0; i<n; i++)
    {
       scanf("%d%d%d", &ai, &bi, &ci);
       minp = min(minp, ai);
       maxp = max(maxp, bi+1);
       adj[ai].pb(Tnode(bi+1, ci));                
    }
    for (int i=minp; i<maxp; i++)
    {
        adj[i+1].pb(Tnode(i, -1));
        adj[i].pb(Tnode(i+1, 0));        
    }
    for (int i=minp; i<=maxp; i++) dis[i] = -oo;
    spfa();    
    return 0;
    }

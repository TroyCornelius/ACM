#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define Maxn 2000
#define oo 999999999
#define pb push_back
using namespace std;

int n, m;
struct Tnode
{
       int id, len;
       Tnode(int a, int b)
       :id(a),len(b){}
       };
vector<Tnode> adj[Maxn];
int dis[Maxn], vis[Maxn];
bool hash[Maxn];
queue<int> q;
bool spfa()
{
     memset(hash, false, sizeof(hash));
     memset(vis, 0, sizeof(vis));
     dis[0] = 0;
     while (!q.empty()) q.pop();
     q.push(0);
     while (!q.empty())
     {
        int now = q.front();
        q.pop();
        hash[now] = false;
        for (int i=0; i<adj[now].size(); i++)
        {
            int v = adj[now][i].id;
            int cost = adj[now][i].len;
            if (dis[v] > dis[now]+cost)
            {
               dis[v] = dis[now] + cost;
               if (!hash[v])
               {
                  q.push(v);
                  hash[v] = true;                            
               }
               if (++vis[v] >= n) return false;                     
            }            
        }           
     }
     return true;
     }

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
       for (int i=0; i<=n; i++) 
       {
           adj[i].clear();
           dis[i] = oo;
       }
       int a, b, c;
       char ch;
       for (int i=0; i<m; i++)
       {
           getchar();
           scanf("%c", &ch);
           if (ch == 'P')
           {
              scanf("%d%d%d", &a, &b, &c);
              adj[b].pb(Tnode(a,c));
              adj[a].pb(Tnode(b,-c));
           }
           else
           {
              scanf("%d%d", &a, &b);
              adj[a].pb(Tnode(b, -1));   
           }           
       }
       for (int i=0; i<=n; i++) adj[0].pb(Tnode(i, 0));

       if (!spfa()) printf("Unreliable\n");
       else printf("Reliable\n");         
    }
    
    
    system("pause");
    return 0;
    }

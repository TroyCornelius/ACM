#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define Maxn 200100
using namespace std;


int n, m, tot, t[Maxn*2],d[Maxn];
int h[Maxn], b[Maxn], c[Maxn];
bool vis[Maxn];
struct edge
{
       int id, next;
       }e[Maxn];
void addedge(int u, int v)
{
     e[tot].id = v;
     e[tot].next = h[u];
     h[u] = tot++;     
     }
void init()
{
     tot = 0;
     memset(vis, false, sizeof(vis));
     memset(h, -1, sizeof(h));
     memset(b, -1, sizeof(b));
     memset(t, 0, sizeof(t));
     }
void dfs(int x)
{
     vis[x] = true;
     b[x] = ++tot;
     
     for (int i=h[x]; i!=-1; i=e[i].next)
     {
         int v = e[i].id;
         if (!vis[v])
         {
            dfs(v);                     
         }         
     }
     c[x] = ++tot;    
     }
void updata(int idx, int val)
{
     for (;idx<=n*2+5; idx+=idx&-idx) t[idx]+=val;
     }
int query(int idx)
{
    int ret = 0;
    for (;idx;idx-=idx&-idx) ret+=t[idx];
    return ret;
    }
int main()
{
    int a, b1;
    char op;
    scanf("%d", &n);
    init();
    for (int i=0; i<n-1; i++)
    {
        scanf("%d%d", &a, &b1);
        addedge(a, b1);
        addedge(b1, a);        
    }
    tot = 0;
    dfs(1);
    for (int i=1; i<=n; i++) 
    {
        updata(c[i], 1);
        d[i] = 1;   
    }
    scanf("%d%*c", &m);
    for (int i=0; i<m; i++)
    {
        scanf("%c %d%*c", &op, &b1);
        if (op == 'Q')
        {
           printf("%d\n", query(c[b1]) - query(b[b1]-1));
        }
        else
        {
            if (d[b1] == 1)
            {
                updata(c[b1], -1);
                d[b1] = 0;         
            }
            else
            {
                updata(c[b1], 1);
                d[b1] = 1;                
            }    
        }        
    }
    system("pause");
    return 0;
    }

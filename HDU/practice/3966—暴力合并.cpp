#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define Maxn 100050
using namespace std;

int n, m, Q, tot, val[Maxn];
struct edeges
{
       int v, next;
       }et[Maxn];
int eh[Maxn], lvl[Maxn], fa[Maxn];
bool vis[Maxn];
void init()
{
     tot = 0;
     memset(eh, -1, sizeof(eh)); 
     memset(fa, -1, sizeof(fa));    
     }
void addedge(int u, int v)
{
     et[tot].v = v;
     et[tot].next = eh[u];
     eh[u] = tot++;
     }
void dfs(int root, int f, int lv)
{
     vis[root] = true;
     lvl[root] = lv; fa[root] = f;
     for (int i=eh[root]; i!=-1; i=et[i].next)
     {
         int v = et[i].v;
         if (!vis[v]) dfs(v, root, lv+1); 
     }
     }
void updata(int a, int b, int c)
{
     int p = a, q = b;
     if (lvl[p] > lvl[q]) swap(p, q); 
     while (lvl[q] > lvl[p])
     {
        val[q] += c;
        q = fa[q];                        
     }
     while (p != q)
     {
        val[p] += c;
        val[q] += c;
        p = fa[p]; q = fa[q];
     }    
     if (p == q) val[p] += c;
     }
int main()
{
    srand(12345);
    int a, b, c;
    char op[2];
    while (scanf("%d%d%d", &n, &m, &Q) != EOF)
    {
          init();
          for (int i=1; i<=n; i++) scanf("%d", &val[i]);
          for (int i=0; i<m; i++)
          {
              scanf("%d%d", &a, &b);
              addedge(a, b);
              addedge(b, a);
          }
          memset(vis, false, sizeof(vis));
          int t = rand() % n + 1;
          dfs(t, -1, 0);          
          for (int i=0; i<Q; i++)
          {
              scanf("%s", op);
              if (op[0] == 'I')
              {
                  scanf("%d%d%d", &a, &b, &c);
                  updata(a, b, c);                        
              }
              else
              if (op[0] == 'D')
              {
                  scanf("%d%d%d", &a, &b, &c);
                  updata(a, b, -c);                        
              }
              else
              {
                  scanf("%d", &a);
                  printf("%d\n", val[a]);                  
              }
          }
    }
    system("pause");
    return 0;
    }

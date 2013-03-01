#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <functional>
#include <set>
#define Maxn 100010
#define Maxm 10010
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef pair<int,int> pii;
int n, m, d[Maxn], ans[Maxn];
int op[Maxm][2], st, tot, max_len;
pii c[Maxn], ask[Maxm];
int fa[Maxn], size[Maxn];
bool vis[Maxn];
bool cmp(const pii &a, const pii &b)
{
     return a.fi < b.fi;
     }
int find(int x)
{
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
    }
void Union(int x, int y)
{
     int r1 = find(x), r2 = find(y);
     if (r1 == r2) return;
     if (size[r1] < size[r2])
     {
        size[r1] += size[r2];
        max_len = max(max_len, size[r1]);
        fa[r2] = r1;                  
     }
     else
     {
         size[r2] += size[r1];
         max_len = max(max_len, size[r2]);
         fa[r1] = r2;         
     }
     return;
     }
void calc(int en)
{
     max_len = 0;
     for (int i=0; i<n; i++) c[i] = mp(d[i], i);
     sort(c, c+n, cmp);     
     tot = 0;
     for (int i=st; i<en; i++) ask[tot++] = mp(op[i][0], i);
     sort(ask, ask+tot, cmp);
     for (int i=0; i<=n; i++) fa[i] = i, size[i] = 1, vis[i] = false;
     
     int p1 = n-1;
     for (int i=tot-1; i>=0; i--)
     {
         while (p1 >= 0 && c[p1].fi >= ask[i].fi)
         {
               vis[c[p1].se] = true;
               if (max_len == 0) max_len = 1;
               if (c[p1].se+1 < n && vis[c[p1].se+1]) Union(c[p1].se, c[p1].se+1);
               if (c[p1].se-1 >=0 && vis[c[p1].se-1]) Union(c[p1].se, c[p1].se-1);  
               p1--;                           
         }
         ans[ask[i].se] = max_len;        
     }     
     }
inline int RD(){
    char c = getchar();
    int t = 0;
    while (c < '0' || c > '9'){
        c = getchar();
    }
    while (c >= '0' && c <= '9'){
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}
int main()
{
    int cmd;
    while (~scanf("%d%d", &n, &m))
    {
          st = 0;
          memset(ans, -1, sizeof(ans));
          for (int i=0; i<n; i++) d[i] = RD();//scanf("%d", &d[i]);
          for (int i=0; i<m; i++)
          {
             // scanf("%d", &cmd);
              cmd = RD();
              if (cmd == 1) op[i][0] = RD();//scanf("%d", &op[i][0]);
              else
              {
                //  scanf("%d%d", &op[i][0], &op[i][1]);
                  op[i][0] = RD(), op[i][1] = RD();
                  calc(i);
                  d[op[i][0]-1] = op[i][1];
                  st = i+1;
              }                          
          }
          if (st < m) calc(m);
          for (int i=0; i<m; i++)
          if (ans[i] != -1) printf("%d\n", ans[i]);
    } 
    return 0;
    }

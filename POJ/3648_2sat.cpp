#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define Maxn 65
#define pb push_back
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)

using namespace std;

int n, m, tot, line[Maxn], cnt;
vector<int> g1[Maxn], g2[Maxn], ng[Maxn];
int col[Maxn], in[Maxn], flag[Maxn];
bool used[Maxn][Maxn];
void init()
{
    REP(i, n+n) g1[i].clear(), g2[i].clear();
}

void dfs1(int u)
{
    col[u] = 1;
    REP(i, g1[u].size())
    {
        int v = g1[u][i];
        if (!col[v]) dfs1(v);       
    }
    line[++tot] = u;    
}
void dfs2(int u)
{
    col[u] = cnt;
    REP(i, g2[u].size())
    {
        int v = g2[u][i];
        if (!col[v]) dfs2(v);
    }
}
void scc()
{
    tot = 0;
    memset(col, 0, sizeof(col));
    REP(i, n+n)
        if (!col[i]) dfs1(i);
    cnt = 0;
    memset(col, 0, sizeof(col));
    for (int i=tot; i>=1; i--)
    {
        if (col[line[i]] == 0)
        {
            cnt++;
            dfs2(line[i]);
        }        
    }    
    return;
}
bool judge()
{
    REP(i, n)
      if (col[i<<1] == col[i<<1|1]) return true;
   // for (int i=0; i<2*n; i+=2)
      //  if (col[i] == col[i+1]) return true;
    return false;
}
void rebuild()
{
    REP(i, n+n+1) ng[i].clear();
    memset(used, false, sizeof(used));
    memset(in, 0, sizeof(in));
    
    REP(i, n+n)
      REP(j, g1[i].size())
      {
          int v = g1[i][j];
          if (col[i] == col[v] || used[col[v]][col[i]]) continue;
          used[col[v]][col[i]] = true;
          ng[col[v]].pb(col[i]);        
          in[col[i]]++;
      }
    return;
}
void toposort()
{
    queue<int> q;
   // while (!q.empty()) q.pop();
    FOR(i, 1, cnt+1)
        if (in[i] == 0) q.push(i);
    tot = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        line[tot++] = u;
        REP(i, ng[u].size())
        {
            int v = ng[u][i];
            in[v]--;
            if (in[v] == 0) q.push(v);
        }        
    }   
    return;
}
void dfs_dag(int u)
{
    flag[u] = 2;
    REP(i, ng[u].size())
    {
        int v = ng[u][i];
        if (flag[v] == 0) dfs_dag(v);
    }
    return;
}
void make_color()
{
    memset(flag, 0, sizeof(flag));
    REP(i, tot)
    {
        if (flag[line[i]] == 0)
        {
            flag[line[i]] = 1;
            REP(j, n+n)
            {
                if (col[j] == line[i])
                {
                    int t = col[j^1];
                    if (flag[t]) continue;
                    dfs_dag(t);                
                }                
            }
        }    
    }
    return;
}
void print_ans()
{
    int k = 0;
    FOR(i, 2, n+n)
    {
        if (flag[col[i]] == flag[col[0]])
        {
            if (k) printf(" ");
            printf("%d%c", i>>1, (i&1)?'h':'w');
            k = 1;
        }
    }
    printf("\n"); 
}
int main()
{
    int a1, a2, x, y;
    char c1, c2;
    while (~scanf("%d%d", &n, &m))
    {
        if (!n && !m) break;
        init();
        REP(i, m)
        {
            scanf("%d%c %d%c",&a1, &c1, &a2, &c2);
            x = a1*2 + (c1 == 'h');
            y = a2*2 + (c2 == 'h');
            g1[x].pb(y^1); g1[y].pb(x^1);
            g2[y^1].pb(x); g2[x^1].pb(y);   
        }
        g1[0].pb(1); g2[1].pb(0);
        scc();
        if (judge())
        {
            printf("bad luck\n");
            continue;
        }
        else
        {
            rebuild();
            toposort();
            make_color();
            print_ans();
        }
    }

    return 0;
}

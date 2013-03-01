#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef long long lint;
#define eps (1e-8)
#define INF (1<<30)
#define PI 3.14159265358979323846
#define MAXN 70
int n, m, cnt;
int col[MAXN];
int id[MAXN];
int sk[MAXN], top;
int qu[MAXN], qs, qe;
int in[MAXN];
int flg[MAXN];
int used[MAXN][MAXN];
vector<int> g[MAXN], rg[MAXN], ng[MAXN];

void add_edge(int x, int y)
{
    g[x].push_back(y);
    rg[y].push_back(x);
}
void dfs1(int u)
{
    int i, v;
    col[u] = 1;
    for (i = 0; i < g[u].size(); i++)
    {
        v = g[u][i];
        if (col[v] == 0) dfs1(v);
    }
    sk[top++] = u;
}

void dfs2(int u)
{
    int i, v;
    col[u] = cnt;
    for (i = 0; i < rg[u].size(); i++)
    {
        v = rg[u][i];
        if (col[v] == 0)
            dfs2(v);
    }
}
void dfs_dag(int u)
{
    int i, v;
    flg[u] = 2;
    for (i = 0; i < ng[u].size(); i++)
    {
        v = ng[u][i];
        if (flg[v] == 0)
            dfs_dag(v);
    }
}
void pr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf ("%d ", a[i]);
    printf ("\n\n");
}

int solve()
{
    int i, j, u, v, t;

    /*scc*/
    memset(col, 0, sizeof(col));
    top = 0;
    for (i = 0; i < 2*n; i++)
        if (col[i] == 0)
            dfs1(i);

    memset(col, 0, sizeof(col));
    cnt = 0;
    for (i = top - 1; i >= 0; i--)
        if (col[sk[i]] == 0)
        {
            ++cnt;
            dfs2(sk[i]);
        }
    /*is legal*/
    for (i = 0; i < 2*n; i += 2)
    {
    //    printf ("col[%d] = %d\n", i, col[i]);
    //    printf ("col[%d] = %d\n", i+1, col[i+1]);
        if (col[i] == col[i+1])
            return 0;
    }

    /* create new graph*/
    for (i = 1; i <= cnt; i++)
        ng[i].clear();

    memset(used, 0, sizeof(used));
    memset(in, 0, sizeof(in));
    for (i = 0; i < 2*n; i++)
        for (j = 0; j < g[i].size(); j++)
        {
            v = g[i][j];
            if (col[i] == col[v] || used[col[v]][col[i]]) continue;
            ng[col[v]].push_back(col[i]);
            in[col[i]]++;
            used[col[v]][col[i]] = 1;
        }
//    printf ("new graph\n");
//    for (i = 1; i <= cnt; i++)
//    {
//        printf ("i %d  ", i);
//        for (j = 0; j < ng[i].size(); j++)
//            printf ("%d ", ng[i][j]);
//        printf ("\n");
//    }
//    printf ("\n");

    /*topo sort*/
    qs = qe = 0;
    for (i = 1; i <= cnt; i++)
        if (in[i] == 0)
        {
            qu[qe++] = i;
        }
    top = 0;
    while (qs < qe)
    {
        u = qu[qs++];
        sk[top++] = u;
        for (i = 0; i < ng[u].size(); i++)
        {
            v = ng[u][i];
            in[v]--;
            if (in[v] == 0)
                qu[qe++] = v;
        }
    }
//    printf ("topo sort\n");
//    pr(sk, top);
    memset(flg, 0, sizeof(flg));
    for (i = 0; i < top; i++)
    {
        if (flg[sk[i]] == 0)
        {
            flg[sk[i]] = 1;
            for (j = 0; j < 2*n; j++)
            {
                if (col[j] == sk[i])
                {
                    t = col[j^1];
                    if (flg[t]) continue;
                    flg[t] = 2;
                    dfs_dag(t);
                }
            }
        }
    }
//    printf ("flg\n");
//    pr(flg, cnt);
    return 1;
}

void pr(vector<int>g[])
{
    int i, j;
    for (i = 0; i < 2*n; i++)
    {
        printf ("i %d  ", i);
        for (j = 0; j < g[i].size(); j++)
            printf ("%d ", g[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int i, j, k, t, csnum, cs;
    int x, y, xx, yy;
    char ch1, ch2;

    while (scanf ("%d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0) break;
        for (i = 0; i < 4*n; i++)
        {
            g[i].clear();
            rg[i].clear();
        }
        for (i = 0; i < m; i++)
        {
            scanf (" %d%c %d%c", &x, &ch1, &y, &ch2);
            x *= 2;
            if (ch1 == 'h')
                x++;
            xx = (x ^ 1);

            y *= 2;
            if (ch2 == 'h')
                y++;
            yy = (y ^ 1);
        //    printf ("%d->%d\n%d->%d\n", x, yy, y, xx);
        //    printf ("x %d xx % d y %d yy %d\n", x, xx, y, yy);
            add_edge(x, yy);
            add_edge(y, xx);
        }
        add_edge(0, 1);
        //pr(g);

        if (!solve())
            printf ("bad luck\n");
        else
        {
            t = flg[col[0]];
        //    pr(col, 2*n);

            k = 0;
            for (i = 2; i < 2*n; i++)
            {
                if (flg[col[i]] == t)
                {
                    if (k) printf (" ");
                    printf ("%d%c", i>>1, (i&1) ? 'h' : 'w');
                    k = 1;
                }
            }
            printf ("\n");
        }
    }
    return 0;
}

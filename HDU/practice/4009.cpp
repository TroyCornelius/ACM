#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define Maxn 1024
#define Maxm 1002000
using namespace std;
const int inf = 1<<30;
int n, m, X, Y, Z;
struct Point
{
    int x,y,z;
}p[Maxn];
struct Edge
{
    int u, v, cost;
    Edge(){}
    Edge(int _u, int _v, int _cost)
    :u(_u), v(_v), cost(_cost){}
}e[Maxm];
int in[Maxn], pre[Maxn], id[Maxn], vis[Maxn];
int directed_MST(int root, int nv, int ne)
{
    int ret = 0;
    while (true)
    {
        REP(i, nv) in[i] = inf;
        REP(i, ne) 
        {
            int u = e[i].u;
            int v = e[i].v;
            if (e[i].cost < in[v] && u != v)
            {
                pre[v] = u;
                in[v] = e[i].cost;            
            }
        }
        REP(i, nv)
        {
            if (i == root) continue;
            if (in[i] == inf) return -1;
        }
        
        int cntcir = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        REP(i, nv)
        {
            ret += in[i];
            int v = i;
            while (vis[v] !=i && id[v]==-1 && v!=root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if (v != root && id[v]==-1)
            {
                for (int u=pre[v]; u!=v; u=pre[u]) id[u] = cntcir;
                id[v] = cntcir++;            
            } 
        }
        if (cntcir == 0) break;
        REP(i, nv)
            if (id[i] == -1) id[i] = cntcir++;
        
        REP(i, ne)
        {
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if (e[i].u != e[i].v) e[i].cost -= in[v];        
        }
        
        nv = cntcir;
        root = id[root];       
    }
    return ret;
}
int getdis(Point a, Point b)
{
    return abs(a.x-b.x) + abs(a.y-b.y) + abs(a.z-b.z);
}
int tot;
int main()
{
    int t, q;
    while (~scanf("%d%d%d%d", &n, &X, &Y, &Z), n)
    {
        if (X==0 && Y==0 && Z==0 && n==0) break;
        tot = 0;
        FOR(i, 1, n+1)
        {
            scanf("%d%d%d", &p[i].x, &p[i].y, & p[i].z);
            e[tot++] = Edge(0, i, abs(p[i].z)*X);    
        }
        FOR(i, 1, n+1)
        {
            scanf("%d", &t);
            while (t--)
            {
                scanf("%d", &q);
                int c = getdis(p[i], p[q]) * Y;            
                if (p[i].z < p[q].z) c += Z;
                e[tot++] = Edge(i, q, c);
            }
        }
        int ans = directed_MST(0, n+1, tot);
        if (ans == -1) printf("poor XiaoA\n");
        else printf("%d\n", ans);
    }
    
    

    return 0;
}

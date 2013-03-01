#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define Maxm 10100
using namespace std;
const double inf = 999999999.9;
typedef pair<double,double> pdd;

int n, m;
pdd p[128];
inline double getdis(pdd a, pdd b)
{
    return sqrt((a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se));
}
struct Edge
{
    int u,v;
    double cost;
}e[Maxm];
int vis[128], pre[128], id[128];
double in[128];
double Directed_MST(int root, int nv, int ne)
{
    double ret = 0;
    while (true)
    {
        REP(i, nv) in[i] = inf;
        REP(i, ne)
        {
            int u = e[i].u, v = e[i].v;
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
        memset(vis, -1, sizeof(vis));
        memset(id, -1, sizeof(id));
        in[root] = 0;
        
        REP(i, nv)
        {
            ret += in[i];
            int v = i;
            while (vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if (v != root && id[v] == -1)
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
            e[i].u = id[e[i].u], e[i].v = id[e[i].v];
            if (e[i].u != e[i].v) e[i].cost -= in[v];
        }
        
        nv = cntcir;
        root = id[root];    
    }
    return ret;
}
int main()
{
    double x, y;
    while (~scanf("%d%d", &n, &m))
    {
        REP(i,n)
        {
            scanf("%lf%lf", &x, &y);
            p[i] = mp(x,y);        
        }
        REP(i, m)
        {
            scanf("%d%d", &e[i].u, &e[i].v);
            //e[i].u = x; e[i].v = y;
            e[i].u--; e[i].v--;
            if (e[i].u != e[i].v) e[i].cost = getdis(p[e[i].u], p[e[i].v]);           
            else e[i].cost = inf; 
        }
        
        double ans = Directed_MST(0, n, m);
        if (ans == -1) printf("poor snoopy\n");
        else printf("%.2f\n", ans);
    }

    return 0;
}


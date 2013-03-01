#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

vi g[Maxn];
int n, k, num[Maxn];
int ans[Maxn];
map<int,int> tot[Maxn];
struct Edge
{
    int v,next;
}et[Maxn+Maxn];
int cnt, eh[Maxn];
int fa[Maxn], col[Maxn];
void init()
{
    cnt = 0;
    memset(eh, -1, sizeof(eh));
}
void addedge(int u, int v)
{
    Edge tmp = {v,eh[u]};
    et[cnt] = tmp;
    eh[u] = cnt++;
}

void merge(int u, int v)
{
    for (map<int,int>::iterator it = tot[v].begin(); it != tot[v].end(); it++)
    {
        if (tot[u].find(it->fi) == tot[u].end())
        {
            tot[u][it->fi] = it->se;
            if (it->se == k) ++col[u];
        }
        else
        if (it->se != 0)
        {
            if (tot[u][it->fi] == k) --col[u];
            tot[u][it->fi] += it->se;
            if (tot[u][it->fi] == k) ++col[u];
        }
    }
    tot[v].clear();
}

void dfs(int u, int father)
{
    tot[u].clear();
    tot[u][num[u]] = 1;
    col[u] = (k == 1);
    for (int i = eh[u]; i != -1; i = et[i].next)
    {
        int v = et[i].v;
        if (v == father) continue;
        dfs(v, u);
        int idu = fa[u], idv = fa[v];
        if (tot[idu].size() > tot[idv].size()) 
        {
            merge(idu, idv);
        }
        else
        {
            merge(idv, idu);
            fa[u] = idv;
        }
    }
    ans[u] = col[fa[u]];
    return;
}
inline int getint()
{
    char c = getchar();
    int t = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
   {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}
int main() 
{
    int T;
    int q, u, v, ca = 0;
    //sf("%d", &T);
    T = getint();
    while (T--)
    {
        //sf("%d%d", &n, &k);
        n = getint(); k = getint();
        init();
        FOR(i, 1, n+1) num[i] = getint();//sf("%d", &num[i]);
        FOR(i, 1, n+1) fa[i] = i;
        REP(i, n-1)
        {
            //sf("%d%d", &u, &v);
            u = getint(); v = getint();
            addedge(u, v);
            addedge(v, u);
        }
        FOR(i, 1, n+1) ans[i] = 0;
        dfs(1, -1);
        //sf("%d", &q);
        q = getint();
        pf("Case #%d:\n", ++ca);
        while (q--)
        {
            //sf("%d", &u);
            u = getint();
            pf("%d\n", ans[u]);
        }
        if (T > 0) puts("");
    }
    return 0;
}


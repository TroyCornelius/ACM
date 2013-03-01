/*
 * Author:  Troy
 * Created Time:  2012/8/5 18:54:18
 * File Name: dynamic_gcd.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <functional>

#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define Maxn 50100
using namespace std;
typedef vector<int> vi;

const int mm = Maxn * 4;
int n, Q, root, tot;
int val[Maxn], nval[Maxn];
int fa[Maxn], dep[Maxn], tid[Maxn], siz[Maxn], top[Maxn], son[Maxn];
//vi edge[Maxn];
int total;
struct Edge
{
    int v, next;
}et[Maxn+Maxn];
int eh[Maxn];
int le[mm], ri[mm], add[mm], fnum[mm], lnum[mm], dif[mm];

void addedge(int u, int v)
{
    Edge e = {v, eh[u]};
    et[total] = e;
    eh[u] = total++;
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

void init()
{
    total = 0;
    memset(eh, -1, sizeof(eh));
    int u, v;
    //sf("%d", &n);
    n = getint();
    REP(i, n-1)
    {
        //sf("%d%d", &u, &v);
        u = getint(); v = getint();
        u++; v++;
        //edge[u].pb(v);
        //edge[v].pb(u);
        addedge(u, v);
        addedge(v, u);
    }
    FOR(i, 1, n+1) val[i] = getint();//sf("%d", &val[i]);
}
void dfs1(int u)
{
    siz[u] = 1; son[u] = 0;
    //REP(i, edge[u].size())
    for (int i = eh[u]; i != -1; i = et[i].next)
    {
        //int v = edge[u][i];
        int v = et[i].v;
        if (v == fa[u]) continue;
        fa[v] = u; dep[v] = dep[u] + 1;
        dfs1(v);
        if (siz[v] > siz[son[u]]) son[u] = v;
        siz[u] += siz[v];
    }
}
void dfs2(int u, int tp)
{
    tid[u] = ++tot; top[u] = tp;
    if (son[u] != 0) dfs2(son[u], top[u]);
    //REP(i, edge[u].size())
    for (int i = eh[u]; i != -1; i = et[i].next)
    {
        //int v = edge[u][i];
        int v = et[i].v;
        if (v != son[u] && v != fa[u]) dfs2(v, v);
    }    
}
void update(int p)
{
    int lson = (p<<1), rson = (p<<1|1);
    fnum[p] = fnum[lson] + add[lson]; lnum[p] = lnum[rson] + add[rson];
    int tmp = abs(fnum[rson] + add[rson] - lnum[lson] - add[lson]);
    dif[p] = __gcd(dif[lson], __gcd(tmp, dif[rson]));
}
void build(int p, int l, int r)
{
    le[p] = l; ri[p] = r; add[p] = 0;
    if (l == r)
    {
        fnum[p] = nval[l];
        dif[p] = 0;
        lnum[p] = nval[r];
        return;
    }
    int mid = (l+r)>>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    update(p);
}
void push_down(int p)
{
    //fnum[p] += add[p]; lnum[p] += add[p];
    add[p<<1] += add[p];
    add[p<<1|1] += add[p];
    add[p] = 0;
}
void insert(int p, int l, int r, int cost)
{
    //cout <<l <<" "<<r <<" in " <<le[p] << " "<<ri[p] <<" "<<fnum[p] <<" " <<add[p] <<endl;
    if (l <= le[p] && ri[p] <= r)
    {
        add[p] += cost;
        return;
    }
    int mid = (le[p] + ri[p]) >>1;
    if (add[p] != 0) push_down(p);
    if (l <= mid) insert(p<<1, l, r, cost);
    if (r > mid) insert(p<<1|1, l, r, cost);
    update(p);
}
int search(int p, int l, int r)
{
    //cout <<l <<" "<<r <<" in " <<le[p] << " "<<ri[p] <<" "<<fnum[p] <<" " <<add[p] <<" " <<dif[p] <<endl;
    if (l <= le[p] && ri[p] <= r) return __gcd(fnum[p]+add[p], dif[p]);
    int mid = (le[p] + ri[p]) >>1, ret = 0;
    if (add[p] != 0) push_down(p);
    if (l <= mid) ret = __gcd(ret, search(p<<1, l, r));
    if (r > mid) ret = __gcd(ret, search(p<<1|1, l, r));
    update(p);
    return ret;
}
void modify(int va, int vb, int cost)
{
    int f1 = top[va], f2 = top[vb];
    while (f1 != f2)
    {
        if (dep[f1] < dep[f2])
        {
            swap(f1, f2);
            swap(va, vb);
        }
        insert(1, tid[f1], tid[va], cost);
        va = fa[f1], f1 = top[va];
    }
    if (dep[va] > dep[vb]) swap(va, vb);
    insert(1, tid[va], tid[vb], cost);
}
int query(int va, int vb)
{
    int f1 = top[va], f2 = top[vb], ret = 0;
    while (f1 != f2)
    {
        if (dep[f1] < dep[f2])
        {
            swap(f1, f2);
            swap(va, vb);
        }
        ret = __gcd(ret, search(1, tid[f1], tid[va]));
        va = fa[f1], f1 = top[va];
    }
    if (dep[va] > dep[vb]) swap(va, vb);
    ret = __gcd(ret, search(1, tid[va], tid[vb]));
    return ret;
}
void work()
{
    char op[3];
    int a, b, c;
    FOR(i, 1, n+1) nval[tid[i]] = val[i];
    build(1, 1, tot);
    //sf("%d", &Q);
    Q = getint();
    while (Q--)
    {
        sf("%s", op);
        a = getint(); b = getint();
        a++; b++;
        if (op[0] == 'F')
        {
            pf("%d\n", query(a, b));
        }
        else
        {
            //sf("%d", &c);
            c = getint();
            if (!c) continue;
            modify(a, b, c);
        }
    }
}
void HLD()
{
    root = (n + 1) / 2;
    //root = rand()%n + 1;
    fa[root] = dep[root] = tot = 0;
    dfs1(root);
    dfs2(root, root);
}
int main() 
{
    //srand(time(NULL));
    freopen("tst.in", "r", stdin);
    freopen("my.out", "w", stdout);
    int start = clock();
    init();
    HLD();
    work();
    //cout <<clock() - start <<endl;
    return 0;
}
/*
5
0 1
1 2
2 3
3 4
10 6 8 14 3
10
C 2 2 13
F 2 2
*/   

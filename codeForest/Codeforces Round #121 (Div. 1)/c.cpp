/*
新版树链剖分，给出一棵树，有2种操作：1.查询两节点之间的距离，2.修改某条边长度
记siz[v]表示以v为根的子树的节点数，dep[v]表示v的深度(根深度为1)，top[v]表示v所在的链的顶端节点，
fa[v]表示v的父亲，son[v]表示与v在同一重链上的v的儿子节点（姑且称为重儿子），tid[v]表示v与其父亲节点的
连边（姑且称为v的父边）在线段树中的位置。只要把这些东西求出来，就能用logn的时间完成原问题中的操作。
*/

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
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

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
#define Maxn 50050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
struct Edge
{
    int v, cost;
    Edge() {}
    Edge(int _v, int _id)
    :v(_v), cost(_id){}
};
vector<Edge> g[Maxn];
int e[Maxn][3];
int root, t[Maxn], tot;
int siz[Maxn], fa[Maxn], dep[Maxn], son[Maxn], tid[Maxn], top[Maxn];

void insert(int idx, int val)
{
    for (;idx <= tot; idx += idx & -idx) t[idx] += val;
}
int query(int idx)
{
    int ret = 0;
    for (; idx; idx -= idx & -idx) ret += t[idx];
    return ret;
}
int qsum(int a, int b)
{
    return query(b) - query(a - 1); 
}
void dfs1(int u)
{
    siz[u] = 1; son[u] = 0;
    REP(i, g[u].size())
    {
        int v = g[u][i].v;
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        if (siz[v] > siz[son[u]]) son[u] = v;
        siz[u] += siz[v];
    } 
}
void dfs2(int u, int tp)
{
    tid[u] = ++tot; top[u] = tp;
    if (son[u] != 0) dfs2(son[u], top[u]);
    REP(i, g[u].size())
    {
        int v = g[u][i].v;
        if (v != son[u] && v != fa[u]) dfs2(v, v);
    }
}
void init()
{
    int u, v, c;
    REP(i, n+1) g[i].clear();
    memset(t, 0, sizeof(t));
    memset(siz, 0, sizeof(siz));;
    root = (n + 1) / 2;   //防止直链
    fa[root]  = tot = dep[root] = 0;   //tot为编码后的总点数
    FOR(i, 1, n)
    {
        sf("%d%d%d", &u, &v, &c);
        e[i][0] = u, e[i][1] = v, e[i][2] = c;
        g[u].pb(Edge(v, c));
        g[v].pb(Edge(u, c));
    }
    dfs1(root);   
    dfs2(root, root); //划分树，重建边的对应编号
    FOR(i, 1, n)
    {
        if (dep[e[i][0]] > dep[e[i][1]]) swap(e[i][0], e[i][1]);
        insert(tid[e[i][1]], e[i][2]);
    }
}

int find(int va, int vb)   //求两点间距离
{
    int f1 = top[va], f2 = top[vb], tmp = 0;
    while (f1 != f2)
    {
        if (dep[f1] < dep[f2])
        {
            swap(f1, f2);
            swap(va, vb);
        }
        tmp += qsum(tid[f1], tid[va]);
        va = fa[f1], f1 = top[va];
    }
    if (va == vb) return tmp;   //如果是求点权，则此句要去掉
    if (dep[va] > dep[vb]) swap(va, vb);   //va, vb在同一条链上
    return tmp + qsum(tid[son[va]], tid[vb]);
    //return tmp + qsum(tid[va], tid[vb]);
}
void work()
{
    int op, a, b;
    while (m--)
    {
        sf("%d%d%d", &op, &a, &b);
        if (op == 0)
        {
            int tmp = qsum(tid[e[a][1]], tid[e[a][1]]);
            insert(tid[e[a][1]], b - tmp);
        }
        else pf("%d\n", find(a, b));
    }
    
}
int main() 
{
    while (~sf("%d", &n))
    {
        init();
        work();
    }
    return 0;
}



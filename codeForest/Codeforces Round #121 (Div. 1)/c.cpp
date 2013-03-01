/*
�°������ʷ֣�����һ��������2�ֲ�����1.��ѯ���ڵ�֮��ľ��룬2.�޸�ĳ���߳���
��siz[v]��ʾ��vΪ���������Ľڵ�����dep[v]��ʾv�����(�����Ϊ1)��top[v]��ʾv���ڵ����Ķ��˽ڵ㣬
fa[v]��ʾv�ĸ��ף�son[v]��ʾ��v��ͬһ�����ϵ�v�Ķ��ӽڵ㣨���ҳ�Ϊ�ض��ӣ���tid[v]��ʾv���丸�׽ڵ��
���ߣ����ҳ�Ϊv�ĸ��ߣ����߶����е�λ�á�ֻҪ����Щ�����������������logn��ʱ�����ԭ�����еĲ�����
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
    root = (n + 1) / 2;   //��ֱֹ��
    fa[root]  = tot = dep[root] = 0;   //totΪ�������ܵ���
    FOR(i, 1, n)
    {
        sf("%d%d%d", &u, &v, &c);
        e[i][0] = u, e[i][1] = v, e[i][2] = c;
        g[u].pb(Edge(v, c));
        g[v].pb(Edge(u, c));
    }
    dfs1(root);   
    dfs2(root, root); //���������ؽ��ߵĶ�Ӧ���
    FOR(i, 1, n)
    {
        if (dep[e[i][0]] > dep[e[i][1]]) swap(e[i][0], e[i][1]);
        insert(tid[e[i][1]], e[i][2]);
    }
}

int find(int va, int vb)   //����������
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
    if (va == vb) return tmp;   //��������Ȩ����˾�Ҫȥ��
    if (dep[va] > dep[vb]) swap(va, vb);   //va, vb��ͬһ������
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



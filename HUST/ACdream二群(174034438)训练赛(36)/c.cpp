/*
 * Author:  Troy
 * Created Time:  2012/6/8 20:04:35
 * File Name: c.cpp
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
#define Maxn 50500
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


int n, t[Maxn*2], root, tot;
int tid[Maxn], fa[Maxn], son[Maxn], dep[Maxn], siz[Maxn], top[Maxn]; 
vi g[Maxn];

void insert(int idx, int val)
{
    for (;idx; idx -= idx & -idx) t[idx] += val;
}
int query(int idx)
{
    int ret = 0;
    for (; idx <= tot; idx += idx & -idx) ret += t[idx];
    return ret;
}

void dfs1(int u)
{
    siz[u] = 1; son[u] = 0;
    REP(i, g[u].size())
    {
        int v = g[u][i];
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
    //cout <<u <<" "<<tid[u] <<endl;
    if (son[u] != 0) dfs2(son[u], top[u]);
    REP(i, g[u].size())
    {
        int v = g[u][i];
        if (v != son[u] && v != fa[u]) dfs2(v, v);
    }
}

void calc(int va, int vb, int c)
{
    int f1 = top[va], f2 = top[vb];
    //cout <<f1 <<"---" <<f2 <<endl;
    while (f1 != f2)
    {
        if (dep[f1] < dep[f2])
        {
            swap(f1, f2);
            swap(va, vb);
        }
        //cout <<f1 <<" "<<f2 <<endl;
        //cout <<tid[va] <<" +++ " <<tid[f1]-1 <<endl;
        insert(tid[va], c);
    //cout <<"done" <<endl;
        insert(tid[f1]-1, -c);
        va = fa[f1], f1 = top[va];
    }
    if (dep[va] > dep[vb]) swap(va, vb);
    insert(tid[vb], c);
    insert(tid[va]-1, -c);
    return;
}
int main() 
{
    int T, u, v, m, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        memset(t, 0, sizeof(t));
        REP(i, n+1) g[i].clear();
        REP(i, n-1)
        {
            sf("%d%d", &u, &v);
            u++; v++;
            g[u].pb(v);
            g[v].pb(u);
        }
        root = (n + 1) / 2;
        fa[root] = dep[root] = tot = 0;
        dfs1(root);
        dfs2(root, root);
        //REP(i, n) cout <<tid[i] <<" ";
        //cout <<endl;
        int a, b,  c;
        sf("%d", &m);
        while(m--)
        {
            sf("%d%d%d", &a, &b, &c);
            a++; b++;
            calc(a, b, c);
        }
        pf("Case #%d:\n", ++ca);
        REP(i, n)
            pf("%d\n", query(tid[i+1]));
    }
    return 0;
}


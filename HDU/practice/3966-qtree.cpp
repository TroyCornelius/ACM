/*
 * Author:  Troy
 * Created Time:  2012/4/15 21:11:18
 * File Name: 3966-qtree.cpp
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

int n, m, q, enemy[Maxn];
vi g[Maxn];
int t[Maxn];
int tot, root;
int fa[Maxn], son[Maxn], dep[Maxn], tid[Maxn], siz[Maxn], top[Maxn];

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
    if (son[u] != 0) dfs2(son[u], top[u]);
    REP(i, g[u].size())
    {
        int v = g[u][i];
        if (v != son[u] && v != fa[u]) dfs2(v, v);
    }
}
void insert(int idx, int val)
{
    for (;idx;idx -= idx & - idx) t[idx] += val;
}
int query(int idx)
{
    int ret = 0;
    for (; idx <= tot; idx += idx & -idx) ret += t[idx];
    return ret;
}
void calc(int va, int vb, int c)
{
    int f1 = top[va], f2 = top[vb];
    //cout <<f1 << " " <<f2 <<endl;
    while (f1 != f2)
    {
        if (dep[f1] < dep[f2])
        {
            swap(f1, f2);
            swap(va, vb);
        }
        //cout <<f1 <<" "<<f2 <<" "<<tid[va] << " "<<tid[f1]-1 <<endl;
        insert(tid[va], c);
        insert(tid[f1]-1, -c);
        va = fa[f1], f1 = top[va];
    }
    if (dep[va] > dep[vb]) swap(va, vb);
    //cout <<va <<" "<<vb <<endl;
    //cout <<tid[son[va]] <<" - "<<tid[vb] <<endl;
    insert(tid[vb], c);   //同一条链上，注意点权要取tid[va] ~ tid[vb]
    insert(tid[va]-1, -c);
    return; 
}
int main() 
{
    int u, v;
    while (~sf("%d%d%d", &n, &m, &q))
    {
        memset(t, 0, sizeof(t));
        REP(i, n+1) g[i].clear();
        FOR(i, 1, n+1) sf("%d", &enemy[i]);
        REP(i, m)
        {
            sf("%d%d", &u, &v);
            g[u].pb(v);
            g[v].pb(u);            
        }
        root = (n + 1) / 2;
        fa[root] = dep[root] = tot = 0;
        dfs1(root);
        dfs2(root, root);
        FOR(i, 1, n+1)
        {
            insert(tid[i], enemy[i]);
            insert(tid[i]-1, -enemy[i]);
        }
        //FOR(i, 1, n+1) cout <<i <<" "<<tid[i] <<" " <<query(tid[i]) <<endl;
        char op[3];
        int a, b, c;
        while (q--)
        {
            sf("%s", op);
            if (op[0] == 'I')
            {
                sf("%d%d%d", &a, &b, &c);
                calc(a, b, c);
            }            
            else
            if (op[0] == 'D')
            {
                sf("%d%d%d", &a, &b, &c);
                calc(a, b, -c);
            }
            else
            {
                sf("%d", &a);
                //cout <<tid[a] <<endl;
                pf("%d\n", query(tid[a]));
            }
        //FOR(i, 1, n+1) cout <<i <<" "<<tid[i] <<" " <<query(tid[i]) <<endl;
        //cout <<endl;
        }
        
    }
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/4/15 15:43:21
 * File Name: d.cpp
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

struct BIT
{
    vi t;
    int size;
    void build(int n)
    {
        t.resize(n+5);
        size = n;        
    }
    void insert(int idx, int val)
    {
        for (; idx <= size; idx += idx & -idx) t[idx] += val;
    }
    int sum(int idx)
    {
        int ret = 0;
        for (; idx ; idx -= idx & -idx) ret += t[idx];
        return ret;
    }
};
vector<BIT> f;
int n, m;
int w[Maxn];
struct Edge
{
    int nxt, id;
    Edge(){}
    Edge(int _nxt, int _id)
    :nxt(_nxt), id(_id){}
};
vector<Edge> g[Maxn];
bool vis[Maxn];
int R[Maxn], E[2*Maxn], L[2*Maxn], rmq[2*Maxn][17];
int tot;
vector<pii> father[Maxn];


void dfs(int rt, int fa, int dep)
{
    if (!vis[rt])
    {
        vis[rt] = true;
        R[rt] = tot;
    }
    E[tot] = rt; L[tot++] = dep;
    REP(i, g[rt].size())
    {
        int v = g[rt][i].nxt;
        if (v == fa) continue;
        father[v].pb(mp(rt, g[rt][i].id));
        dfs(v, rt, dep+1);
        E[tot] = rt;
        L[tot++] = dep; 
    }
}
void creattable()
{
    for (int j = 0; (1<<j) <= tot; j++)
        for (int i = 0; i + (1<<j) <= tot; i++)
        {
            if (j == 0) rmq[i][j] = i;
            else
            {
                if (L[rmq[i][j-1]] < L[rmq[i+(1<<(j-1))][j-1]]) rmq[i][j] = rmq[i][j-1];
                else rmq[i][j] = rmq[i+(1<<(j-1))][j-1];
            }
        }
}
int get_RMQ(int v1, int v2)
{
    int k = 0;
    while (1<<(k+1) < (v2 - v1 + 1)) k++;
    if (L[rmq[v1][k]] < L[rmq[v2 - (1<<k) + 1][k]]) return E[rmq[v1][k]];
    else return E[rmq[v2 - (1<<k) + 1][k]]; 
}
int LCA(int v1, int v2)
{
    if (R[v1] < R[v2]) return get_RMQ(R[v1], R[v2]);
    else return get_RMQ(R[v2], R[v1]);
}
int main() 
{
    int u, v, c;
    while (~sf("%d%d", &n, &m))
    {
        REP(i, n) 
        {
            g[i].clear();
            father[i].clear();
        }
        FOR(i, 1, n)
        {
            sf("%d%d%d", &u, &v, &w[i]);
            g[u].pb(Edge(v, i));
            g[v].pb(Edge(u, i));
        }
        w[0] = 0;
        father[1].pb(mp(1, 0));
        memset(vis, false, sizeof(vis));
        tot = 0;
        dfs(1, 1, 0);
        creattable();
        int op;
   /*     while (m--)
        {
            sf("%d%d%d", &op, &a, &b);
            if (op == 0)
            {
                
            }
        }*/
        FOR(i, 1, n+1)
        {
            cout <<i <<" : " <<endl;
            REP(j, father[i].size())
            {
                cout <<father[i][j].fi <<" "<<father[i][j].se <<endl;
            }
            cout <<endl;
        }
    }
    return 0;
}


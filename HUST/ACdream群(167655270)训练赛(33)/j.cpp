/*
 * Author:  Troy
 * Created Time:  2012/5/18 20:52:25
 * File Name: j.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, q, m;
vector<pii> g[210];
int fa[210], ans;
pii edge;
int findfa(int x)
{
    if (fa[x] == x) return x;
    else return fa[x] = findfa(fa[x]);
}
void bfs(int s, int t, int cn)
{
    pii rec[210];
    int dist[210];
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        REP(i, g[now].size())
        {
            int v = g[now][i].fi, cost = g[now][i].se;
            if (dist[v] != -1) continue;
            if (cost > dist[now])
            {
                dist[v] = cost;
                rec[v] = mp(now, v);
            }
            else 
            {
                dist[v] = dist[now];
                rec[v] = rec[now];
            }
            que.push(v);
        }
    }
    if (dist[t] > cn)
    {
        ans -= dist[t];
        int x = rec[t].fi, y = rec[t].se;
        for (vector<pii>::iterator it = g[x].begin(); it != g[x].end(); it++)
            if (it->fi == y)
            {
                g[x].erase(it);
                break;
            }

        for (vector<pii>::iterator it = g[y].begin(); it != g[y].end(); it++)
            if (it->fi == x)
            {
                g[y].erase(it);
                break;
            }
        ans += cn;
        g[s].pb(mp(t, cn));
        g[t].pb(mp(s, cn));
    }
    return;

}
int main() 
{
    int T, ca = 0, u, v, c;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &q);
        REP(i, n+1) {g[i].clear(); fa[i] = i;}
        m = ans = 0;
        //vis.clear();
        pf("Case %d:\n", ++ca);
        while (q--)
        {
            sf("%d%d%d", &u, &v, &c);
            //if (u > v) swap(u, v);
            int x = findfa(u), y = findfa(v);
            if (x != y)
            {
                m++;
                fa[x] = y;
                //vis.insert(mp(u, v));         
                ans += c;
                g[u].pb(mp(v, c));
                g[v].pb(mp(u, c));
            }
            else
            {
                bfs(u, v, c);                
            }
            if (m == n-1) pf("%d\n", ans);
            else pf("-1\n");
        }

    }
    return 0;
}


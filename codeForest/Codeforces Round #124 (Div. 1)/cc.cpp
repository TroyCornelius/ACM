/*
 * Author:  Troy
 * Created Time:  2012/6/13 1:04:31
 * File Name: cc.cpp
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
#define Maxn 1600
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


int n, ans[Maxn];
vi g[Maxn];
pii p[Maxn];
int sz[Maxn];
void dfs(int u, int fa)
{
    sz[u] = 1;
    REP(i, g[u].size())
    {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];     
    }
}
int main() 
{
    int u, v;
    sf("%d%d", &u, &v);
    REP(i, n-1)
    {
        sf("%d%d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi a;
    REP(i, n)
    {
        sf("%d%d", &p[i].fi, &p[i].se);
        a.pb(i);
    }
    dfs(0, -1);
    gao(a, 0, -1);
    return 0;
}


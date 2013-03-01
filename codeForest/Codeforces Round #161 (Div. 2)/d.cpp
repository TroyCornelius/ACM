/*
 * Author:  Troy
 * Created Time:  2013/1/17 0:02:21
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
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 100050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, k, ans;
int vis[Maxn], fa[Maxn];
pii pt;
vi g[Maxn];

void dfs(int u, int len) {
    vis[u] = len;
    REP(i, g[u].size()) {
        int v = g[u][i];
        if (!vis[v])  {
            fa[v] = u;
            dfs(v, len+1);
        }
        else {
            int tmp = vis[u] - vis[v] + 1;
            if (tmp > ans) {
                ans = tmp;
                pt = mp(u, v);
            }
        }
    }
}
int main() {
    sf("%d%d%d", &n, &m, &k);
    int u, v;
    REP(i, m) {
        sf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(vis, 0, sizeof(vis));
    memset(fa, -1, sizeof(fa));
    ans = 0;
    FOR(i, 1, n+1)
        if (!vis[i]) dfs(i, 1);
    pf("%d\n", ans);
    pf("%d", pt.fi);
    u = pt.fi;
    while (u != pt.se) {
        u = fa[u];
        pf(" %d", u);
    }
    
    puts("");
    return 0;
}


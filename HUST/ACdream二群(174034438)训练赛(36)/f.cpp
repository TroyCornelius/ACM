/*
 * Author:  Troy
 * Created Time:  2012/6/8 20:50:24
 * File Name: f.cpp
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
#define Maxn 3000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, ans;
vi g[Maxn];
bool vis[Maxn];
void dfs(int u)
{
    if (vis[u]) return;
    vis[u] = true;
    REP(i, g[u].size()) dfs(g[u][i]);
}
int main() 
{
    int T, u, v;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        REP(i, n+1) g[i].clear();
        REP(i, m)
        {
            sf("%d%d", &u, &v);
            u--; v--;
            g[u].pb(v);
        }
        ans = 0;
        REP(i, n)
        {
            memset(vis, false, sizeof(vis));
            REP(j, g[i].size()) dfs(g[i][j]);
            REP(j, n)
                if (i != j && vis[j]) ans++;
        }
        pf("%d\n", ans);
    }
    return 0;
}

